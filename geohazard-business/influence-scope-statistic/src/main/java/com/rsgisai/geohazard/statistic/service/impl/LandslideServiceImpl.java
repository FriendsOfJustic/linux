package com.rsgisai.geohazard.statistic.service.impl;

import com.rsgisai.geohazard.entity.Correlation;
import com.rsgisai.geohazard.entity.Landslide;
import com.rsgisai.geohazard.statistic.dao.mysql.LandslideDao;
import com.rsgisai.geohazard.statistic.exception.LandslideException;
import com.rsgisai.geohazard.statistic.feign.CorrelationClient;
import com.rsgisai.geohazard.statistic.service.LandslideService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class LandslideServiceImpl implements LandslideService {
    @Resource
    private LandslideDao landslideDao;
    @Resource
    private CorrelationClient correlationClient;

    @Override
    public List<Landslide> list() {
        return landslideDao.list();
    }

    @Override
    public Landslide selectById(Integer id) {
        Landslide landslide = landslideDao.selectById(id);
        if (landslide == null) {
            throw new LandslideException("no landslide record with id=" + id);
        }
        return landslide;
    }

    @Override
    public Correlation correlation() {
        Correlation correlation = new Correlation();
        List<Landslide> list = landslideDao.list();
        List<List<Double>> data = list.stream()
                .map(landslide -> {
                    List<Double> l = new ArrayList<>(3);
                    l.add(landslide.getVolume());
                    l.add(landslide.getTheta());
                    l.add(landslide.getHeight());
                    return l;
                })
                .collect(Collectors.toList());
        List<List<Double>> matrix = correlationClient.correlation(data);
        correlation.setMatrix(matrix);

        List<Boolean> validList = new ArrayList<>(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            validList.add(matrix.get(i).get(i) != 0);
        correlation.setValidList(validList);

        return correlation;
    }
}
