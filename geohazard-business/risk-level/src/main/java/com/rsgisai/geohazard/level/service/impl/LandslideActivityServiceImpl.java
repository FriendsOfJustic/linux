package com.rsgisai.geohazard.level.service.impl;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.level.client.LandslideActivityClient;
import com.rsgisai.geohazard.level.dao.pgsql.LandslideActivityModelDao;
import com.rsgisai.geohazard.level.dao.pgsql.LandslidePotentialDao;
import com.rsgisai.geohazard.level.entity.LandslidePotential;
import com.rsgisai.geohazard.level.service.LandslideActivityService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.LinearModel;
import com.rsgisai.geohazard.system.common.service.FileStorageService;
import com.rsgisai.geohazard.system.common.service.impl.FileStorageServiceImpl;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import com.rsgisai.util.math.XLSParser;

import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author tfh, created at 2023-05-24 11:40 PM
 */
@Slf4j
@Service
public class LandslideActivityServiceImpl implements LandslideActivityService {
    FileStorageService fileStorageService = new FileStorageServiceImpl(LandslideActivityServiceImpl.class);

    @Autowired
    LandslideActivityClient landslideActivityClient;

    @Autowired
    ObjectMapper objectMapper;

    @Autowired
    LandslideActivityModelDao landslideActivityModelDao;
    private XLSParser xlsParser = new XLSParser();
    @Qualifier("landslidePotentialDao")
    @Autowired
    private LandslidePotentialDao landslidePotentialDao;

    @Override
    public LinearModel train(MultipartFile xls) throws IOException {
        // 1. save file
//        Path path = fileStorageService.saveTmp(xls);
//        String absolutePath = path.toAbsolutePath().toString();
//        log.info("tmp file saved to: " + absolutePath);

        // call geohazard-gis
//        R<LinearModel> train = landslideActivityClient.train(absolutePath);
        R<LinearModel> train = landslideActivityClient.train(xls);
        LinearModel model = train.getData();

        // save model
        model.serializedObject = objectMapper.writeValueAsString(model);
        landslideActivityModelDao.insert(model);

        return model;
    }

    @Override
    public Path evaluate(MultipartFile xls) throws IOException {
        LinearModel linearModel = objectMapper.readValue(
                landslideActivityModelDao.selectLast().getSerializedObject(),
                LinearModel.class);

        Path path = fileStorageService.saveTmp(xls);
        List<Map<String, Double>> maps = xlsParser.parseXLS(path.toAbsolutePath().toString());
        List<Double> predictions = new ArrayList<>();
        for (Map<String, Double> input : maps) {
            double prediction = predict(linearModel, input);
            predictions.add(prediction);
        }
        xlsParser.addColumn(path.toAbsolutePath().toString(), predictions);
        return path;
    }

    @Override
    public LandslidePotential evaluate(String no) throws JsonProcessingException {
        LinearModel linearModel = objectMapper.readValue(
                landslideActivityModelDao.selectLast().getSerializedObject(),
                LinearModel.class);
        Map<String, Object> objectMap = landslidePotentialDao.selectParam(no);
        HashMap<String, Double> doubleMap = new HashMap<>();
        objectMap.forEach((s, o) -> {
            if (o instanceof Number) {
                doubleMap.put(s, ((Number) o).doubleValue());
            }
        });

        double activityValue = predict(linearModel, doubleMap);
        String activityLevel = getActivityLevel(activityValue);

        // save
        landslidePotentialDao.updateActivity(no, activityLevel);

        LandslidePotential landslidePotential = new LandslidePotential();
        landslidePotential.setNo(no);
        landslidePotential.setActivityLevel(activityLevel);
        landslidePotential.setActivityValue(activityValue);
        return landslidePotential;
    }

    static String[] activityLevels = new String[]{
            "低", "中", "高", "极高"
    };

    static public String getActivityLevel(double activityValue) {
        if (activityValue < 0 || activityValue > 1)
            throw new RuntimeException("activity value should belong to [0, 1], activity value = " + activityValue);
        int i = (int) (activityValue * 4.0);
        if (i >= activityLevels.length)
            i = activityLevels.length - 1;
        return activityLevels[i];
    }

    private double predict(LinearModel linearModel, Map<String, Double> input) {
        double logit = linearModel.getBias()
                +
                linearModel.getWeight().entrySet().stream().
                        map(entry ->
                                entry.getValue() * input.get(entry.getKey()))// 加权
                        .mapToDouble(Double::doubleValue).sum();// 求和
        return 1.0 / (1.0 + Math.exp(-logit));
    }
}
