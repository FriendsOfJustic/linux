package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.dao.pgsql.*;
import com.rsgisai.geohazard.level.entity.RasterStats;
import com.rsgisai.geohazard.level.entity.Xxl;
import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;
import com.rsgisai.geohazard.level.service.AlgorithmService;
import com.rsgisai.geohazard.level.service.ReclassifyUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * @author tfh, created at 2023-02-14 10:38 AM
 */
@Service
public class AlgorithmServiceImpl implements AlgorithmService {
    private final String[] FEATURES = new String[]{"dem", "slope", "aspect", "curvature"};
    @Autowired
    private DemDao demDao;
    @Autowired
    private DemAlgorithmDao demAlgorithmDao;
    @Autowired
    private SlopeAlgorithmDao slopeAlgorithmDao;
    @Autowired
    private AspectAlgorithmDao aspectAlgorithmDao;
    @Autowired
    private CurvatureAlgorithmDao curvatureAlgorithmDao;
    @Autowired
    private AlgorithmDao algorithmDao;

    private AspectAlgorithm aspectAlgorithm = new AspectAlgorithm();
    private DemAlgorithm demAlgorithm = new DemAlgorithm();
    private CurvatureAlgorithm curvatureAlgorithm = new CurvatureAlgorithm();
    @Autowired
    private EvaluationAlgorithmDao evaluationAlgorithmDao;
    @Autowired
    private PublishServiceImpl publishService;

    @Override
    public void calculateDerived(Long workingAreaId, String feature) {
        switch (feature.toLowerCase()) {
            case "slope":
                slopeAlgorithmDao.generate(workingAreaId);
                break;
            case "aspect":
                aspectAlgorithmDao.generate(workingAreaId);
                break;
            case "curvature":
                // todo
                throw new RuntimeException("Feature " + feature + " not supported.");
//                break;
            default:
                throw new RuntimeException("Feature " + feature + " not supported.");
        }
    }


    @Override
    public void calculateAllDerived(Long workingAreaId) {

    }

    @Override
    public void reclassify(long workingAreaId, String feature, int numberClasses) throws SusceptibilityAlgorithmException {
        // check if dem exist
        RasterRecord dem = demDao.select(new RasterRecord(null, workingAreaId));
        if (dem == null) throw new SusceptibilityAlgorithmException("original DEM don't exist.");
        RasterStats stats;
        switch (feature.toLowerCase()) {

            case "dem":
                stats = demDao.getStats(new RasterRecord(null, workingAreaId));
                demAlgorithmDao.reclassify(workingAreaId, ReclassifyUtil.generateReclassexpr(numberClasses, stats.getMin(), stats.getMax()), numberClasses);
                break;
            case "slope":
                stats = slopeAlgorithmDao.getStats(new RasterRecord(null, workingAreaId));
                slopeAlgorithmDao.reclassify(workingAreaId, ReclassifyUtil.generateReclassexpr(numberClasses, stats.getMin(), stats.getMax()), numberClasses);
                break;
            case "aspect":
                aspectAlgorithmDao.reclassify(workingAreaId, aspectAlgorithm.generateReclassexpr(numberClasses), numberClasses);
                break;
            case "curvature":
                stats = curvatureAlgorithmDao.getStats(new RasterRecord(null, workingAreaId));
                curvatureAlgorithmDao.reclassify(workingAreaId,
                        curvatureAlgorithm.generateReclassexpr(numberClasses, stats.getMin(), stats.getMax()),
                        numberClasses);
                break;
            default:
                throw new SusceptibilityAlgorithmException("Reclassify " + feature + " not supported.");
        }
    }

    @Override
    public int generateXxlInRaster(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException {
        int count = 0;
        // dem
        count += demXxlRasterGenerate(workingAreaId, numberClasses);
        // slope
        count += slopeXxlRasterGenerate(workingAreaId, numberClasses);
//        // aspect
        count += aspectXxlRasterGenerate(workingAreaId, numberClasses);
//        // curvature
        count += curvatureXxlRasterGenerate(workingAreaId, numberClasses);
        return count;
    }

    private int demXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException {
        // 检查 dem_reclassify 数据
        if (!demAlgorithmDao.reclassifyExist(workingAreaId, numberClasses)) {
            reclassify(workingAreaId, "dem", numberClasses);
            publishService.publishDemReclassifyRaster(workingAreaId, numberClasses);
        }
        // 生成 dem 信息量 栅格
        List<Xxl> xxlList;
        demAlgorithmDao.updateLevelCount(workingAreaId, numberClasses);
        demAlgorithmDao.updateJoinCount(workingAreaId, numberClasses);
        xxlList = demAlgorithmDao.getXxlMapping(workingAreaId, numberClasses);
        String expression = generateXxlMappingExpression(xxlList, numberClasses);
        return demAlgorithmDao.xxlMapping(workingAreaId, numberClasses, expression);
    }

    @Override
    public int slopeXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException {
        // 检查 slope_reclassify 数据
        if (!slopeAlgorithmDao.reclassifyExist(workingAreaId, numberClasses)) {
            reclassify(workingAreaId, "slope", numberClasses);
            publishService.publishRaster("slope_reclassify", workingAreaId, numberClasses);
        }
        // 生成 slope 信息量 栅格
        slopeAlgorithmDao.updateLevelCount(workingAreaId, numberClasses);
        slopeAlgorithmDao.updateJoinCount(workingAreaId, numberClasses);
        List<Xxl> xxlList = slopeAlgorithmDao.getXxlMapping(workingAreaId, numberClasses);// 获取重分类规则
        String expression = generateXxlMappingExpression(xxlList, numberClasses);
        return slopeAlgorithmDao.xxlMapping(workingAreaId, numberClasses, expression);// 执行重分类
    }

    @Override
    public int aspectXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException {
        // 检查 aspect_reclassify 数据
        if (!aspectAlgorithmDao.reclassifyExist(workingAreaId, numberClasses)) {
            reclassify(workingAreaId, "aspect", numberClasses);
            publishService.publishRaster("aspect_reclassify", workingAreaId, numberClasses);
        }
        // 生成 aspect 信息量 栅格
        aspectAlgorithmDao.updateLevelCount(workingAreaId, numberClasses);
        aspectAlgorithmDao.updateJoinCount(workingAreaId, numberClasses);
        List<Xxl> xxlList = aspectAlgorithmDao.getXxlMapping(workingAreaId, numberClasses);
        String expression = generateXxlMappingExpression(xxlList, numberClasses);
        return aspectAlgorithmDao.xxlMapping(workingAreaId, numberClasses, expression);
    }

    @Override
    public int curvatureXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException {
        // 检查 curvature_reclassify 数据
        if (!curvatureAlgorithmDao.reclassifyExist(workingAreaId, numberClasses)) {
            reclassify(workingAreaId, "curvature", numberClasses);
            publishService.publishRaster("curvature_reclassify", workingAreaId, numberClasses);
        }
        // 生成 curvature 信息量 栅格
        List<Xxl> xxlList;
        String expression;
        curvatureAlgorithmDao.updateLevelCount(workingAreaId, numberClasses);
        curvatureAlgorithmDao.updateJoinCount(workingAreaId, numberClasses);
        xxlList = curvatureAlgorithmDao.getXxlMapping(workingAreaId, numberClasses);
        expression = generateXxlMappingExpression(xxlList, numberClasses);
        return curvatureAlgorithmDao.xxlMapping(workingAreaId, numberClasses, expression);
    }


    /**
     * @param xxlList
     * @param numberClasses
     * @return 返回 ST_Reclass 的 reclassexpr 分类表达式
     */
    private String generateXxlMappingExpression(List<Xxl> xxlList, int numberClasses) {
        ArrayList<String> mappingList = new ArrayList<>();
        mappingList.add("0:7654321");

        // map to no data, 重分类里使用的是0表示nodata，而信息量里也可能出现0，所以需要将nodata换成其他数值
        // 信息量一般不超过正负10，所以我们使用 7654321 表示nodata

        HashMap<Integer, Double> map = new HashMap<>();
        for (Xxl xxl : xxlList) {
            map.put(xxl.getLevel(), xxl.getXxl());
        }

        for (int i = 0; i < numberClasses; i++) {
            int I = i + 1;
            mappingList.add(String.format("%d:%f", I, map.getOrDefault(I, 0D)));
        }
        return String.join(", ", mappingList);
    }

    @Override
    public String generateReclassexpr(int outNumClass, double min, double max) {

        double range = max - min;
        double delta = range / outNumClass;// 分类间隔

        double leftMost = min - 1;
        double rightMost = max + 1;
        ArrayList<String> roles = new ArrayList<>(outNumClass);

        for (int i = 0; i < outNumClass; i++) {// 注意总共 outNumClass 个类别，这里要减一
            double left = i == 0 ? leftMost : (min + i * delta);
            double right = i == (outNumClass - 1) ? rightMost : min + (i + 1) * delta;// 确保相邻区间的 left-right 相等
            int I = i + 1;
            roles.add(String.format("[%f-%f):%d", left, right, I));
        }
        return String.join(", ", roles);
    }


    @Override
    public void calculateEvaluation(
            long workingAreaId,
            Integer demNumberClasses,
            Integer slopeNumberClasses,
            Integer aspectNumberClasses,
            Integer curvatureNumberClasses,
            Integer outNumClass) throws SusceptibilityAlgorithmException, IOException {
        // check dem xxl
        if (!demAlgorithmDao.xxlExist(workingAreaId, demNumberClasses)) {
            demXxlRasterGenerate(workingAreaId, demNumberClasses);
        }
        // check slope xxl
        if (!slopeAlgorithmDao.xxlExist(workingAreaId, slopeNumberClasses)) {
            slopeXxlRasterGenerate(workingAreaId, slopeNumberClasses);
        }
        // check aspect xxl
        if (!aspectAlgorithmDao.xxlExist(workingAreaId, aspectNumberClasses)) {
            aspectXxlRasterGenerate(workingAreaId, aspectNumberClasses);
        }
        // check curvature xxl
        if (!curvatureAlgorithmDao.xxlExist(workingAreaId, curvatureNumberClasses)) {
            curvatureXxlRasterGenerate(workingAreaId, curvatureNumberClasses);
        }
        evaluationAlgorithmDao.calculateTotalInformationAmount(
                workingAreaId, demNumberClasses, slopeNumberClasses, aspectNumberClasses, curvatureNumberClasses);
        calculateEvaluationReclassify(
                workingAreaId, demNumberClasses, slopeNumberClasses, aspectNumberClasses, curvatureNumberClasses, outNumClass);
    }

    private void calculateEvaluationReclassify(long workingAreaId, Integer demNumberClasses, Integer slopeNumberClasses, Integer aspectNumberClasses, Integer curvatureNumberClasses, Integer outNumberClasses) throws IOException {
        RasterStats stats = evaluationAlgorithmDao.getStats(workingAreaId, demNumberClasses, slopeNumberClasses, aspectNumberClasses, curvatureNumberClasses, outNumberClasses);
        String reclassifyExpression = generateReclassexpr(outNumberClasses, stats.getMin(), stats.getMax());
        evaluationAlgorithmDao.calculateEvaluationReclassify(
                workingAreaId, demNumberClasses, slopeNumberClasses, aspectNumberClasses, curvatureNumberClasses, outNumberClasses, reclassifyExpression);
    }


}
