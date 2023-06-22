package com.rsgisai.geohazard.computation.geospatial.service.impl;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.BuiltInOperatorDao;
import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.InformationAmountDao;
import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.RasterAlgebraDao;
import com.rsgisai.geohazard.computation.geospatial.entity.*;
import com.rsgisai.geohazard.computation.geospatial.service.BuiltInOperatorService;
import com.rsgisai.geohazard.computation.geospatial.service.InformationAmountUtil;
import com.rsgisai.geohazard.computation.geospatial.service.MapAlgebraUtil;
import com.rsgisai.geohazard.computation.geospatial.service.ReclassifyUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
public class BuiltInOperatorServiceImpl implements BuiltInOperatorService {
    @Autowired
    BuiltInOperatorDao builtInOperatorDao;
    @Qualifier("informationAmountDao")
    @Autowired
    private InformationAmountDao informationAmountDao;
    @Qualifier("rasterAlgebraDao")
    @Autowired
    private RasterAlgebraDao rasterAlgebraDao;


    private static final ObjectMapper objectMapper = new ObjectMapper();

    @Override
    public long DZ_OriginRaster(QueryMeta queryMeta, String feature) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setFeature(feature);
        builtInOperatorDao.prepareRaster(rasterQuery);
        return rasterQuery.getId();
    }

    @Override
    public long DZ_ResultRaster(QueryMeta queryMeta, String feature) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setFeature(feature);
        builtInOperatorDao.prepareResultRaster(rasterQuery);
        return rasterQuery.getId();
    }

    @Override
    public long DZ_OriginPoints(QueryMeta queryMeta, String feature) {
        PointsQuery pointsQuery = new PointsQuery(queryMeta.workingAreaId, queryMeta.userId);
        pointsQuery.setFeature(feature);
        builtInOperatorDao.preparePoints(pointsQuery);
        return pointsQuery.getId();
    }

    @Override
    public long DZ_Slope(QueryMeta queryMeta, long rasterId) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        builtInOperatorDao.calculateSlope(rasterQuery);
        return rasterQuery.getId();
    }

    @Override
    public long DZ_Aspect(QueryMeta queryMeta, long rasterId) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        builtInOperatorDao.calculateAspect(rasterQuery);
        return rasterQuery.getId();
    }

    @Override
    public long DZ_EqualIntervalReclassify(QueryMeta queryMeta, long rasterId, Integer numberClasses) {
        RasterStats rasterStats = builtInOperatorDao.queryStats(rasterId);
        String reclassExpression = ReclassifyUtil.generateReclassexpr(numberClasses, rasterStats.min, rasterStats.max);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        rasterQuery.setFeature("reclassify");
        rasterQuery.setAlgorithm("DZ_EqualIntervalReclassify");
        rasterQuery.setNumberClasses(numberClasses);
        rasterQuery.setReclassifyExpression(reclassExpression);

        builtInOperatorDao.reclassify(rasterQuery);

        return rasterQuery.getId();
    }

    @Override
    public long DZ_AspectReclassify(QueryMeta queryMeta, long rasterId, Integer numberClasses) {
        String reclassExpression = ReclassifyUtil.generateAspectReclassexpr(numberClasses);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        rasterQuery.setFeature("reclassify");
        rasterQuery.setAlgorithm("DZ_AspectReclassify");
        rasterQuery.setNumberClasses(numberClasses);
        rasterQuery.setReclassifyExpression(reclassExpression);

        builtInOperatorDao.reclassify(rasterQuery);

        return rasterQuery.getId();
    }

    @Override
    public long DZ_InformationAmount(QueryMeta queryMeta, long reclassifyRaster, long points, Integer numberClasses) {

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.numberClasses = numberClasses;
        rasterQuery.feature = reclassifyRaster + "|" + points + "|" + numberClasses;// just to identify the intermediate result
        rasterQuery.inputRasterId = reclassifyRaster;
        rasterQuery.inputPointsId = points;

        informationAmountDao.clearJoinCount(rasterQuery);
        informationAmountDao.calculateJoinCount(rasterQuery);
        informationAmountDao.clearLevelCount(rasterQuery);
        informationAmountDao.calculateLevelCount(rasterQuery);

        List<InformationAmount> informationAmountMapping = informationAmountDao.getInformationAmountMapping(rasterQuery);
        rasterQuery.reclassifyExpression =
                InformationAmountUtil.generateXxlMappingExpression(informationAmountMapping, numberClasses);

        int i = informationAmountDao.populateInformationAmount(rasterQuery);
        return rasterQuery.id;
    }

    @Override
    public long DZ_RasterSum(QueryMeta queryMeta, long... rasterList) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.inputRasterId = rasterList[0];
        for (int i = 1; i < rasterList.length; i++) {
            rasterQuery.inputRasterId2 = rasterList[i];
            rasterAlgebraDao.rasterSum(rasterQuery);
            rasterQuery.inputRasterId = rasterQuery.id;
        }
        return rasterQuery.id;
    }

    @Override
    public long DZ_RasterSum3(QueryMeta queryMeta, long raster1, long raster2, long raster3) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.inputRasterId = raster1;
        rasterQuery.inputRasterId2 = raster2;
        rasterAlgebraDao.rasterSum(rasterQuery);

        rasterQuery.inputRasterId = rasterQuery.id;
        rasterQuery.inputRasterId2 = raster3;
        rasterAlgebraDao.rasterSum(rasterQuery);

        return rasterQuery.id;
    }

    @Override
    public long DZ_RasterSum5(QueryMeta queryMeta, long raster1, long raster2, long raster3, long raster4, long raster5) {
        return DZ_RasterSum(queryMeta, raster1, raster2, raster3, raster4, raster5);
    }

    @Override
    public long DZ_SaveRaster(QueryMeta queryMeta, long raster, String feature, String algorithm, Object[] args) {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.inputRasterId = raster;
        rasterQuery.feature = feature;
        rasterQuery.algorithm = algorithm;
        rasterQuery.algorithmArgs = Arrays.toString(args);
        builtInOperatorDao.saveRaster(rasterQuery);


        return rasterQuery.getId();
    }

    @Override
    public long SaveRaster(QueryMeta queryMeta, long raster, String feature, String algorithm,
                           SortedMap<String, Object> args) throws JsonProcessingException {
        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.inputRasterId = raster;
        rasterQuery.feature = feature;
        rasterQuery.algorithm = algorithm;
        rasterQuery.algorithmArgs = objectMapper.writeValueAsString(args);
        builtInOperatorDao.saveRaster(rasterQuery);
        return rasterQuery.getId();
    }

    @Override
    public long DZ_Normalize(QueryMeta queryMeta, long rasterId) {
        RasterStats rasterStats = builtInOperatorDao.queryStats(rasterId);
        Double min = rasterStats.min;
        Double max = rasterStats.max;

        String mapAlgebraExpression = MapAlgebraUtil.generateNormalizeExpression(min, max);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        rasterQuery.setFeature("normalize");
        rasterQuery.setAlgorithm("DZ_Normalize");
        rasterQuery.setMapAlgebraExpression(mapAlgebraExpression);

        builtInOperatorDao.singleMapAlgebra(rasterQuery);

        return rasterQuery.getId();
    }

    @Override
    public long DZ_NormalizeClassified(QueryMeta queryMeta, long rasterId) {

        RasterStats rasterStats = builtInOperatorDao.queryStats(rasterId);
//        Double min = rasterStats.min;
        Double max = rasterStats.max;

        String mapAlgebraExpression = MapAlgebraUtil.generateNormalizeClassifiedExpression(max);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        rasterQuery.setFeature("normalize_classified");
        rasterQuery.setAlgorithm("DZ_NormalizeClassified");
        rasterQuery.setMapAlgebraExpression(mapAlgebraExpression);

        builtInOperatorDao.singleMapAlgebra(rasterQuery);

        return rasterQuery.getId();

    }

    @Override
    public long DZ_Proportion(QueryMeta queryMeta, long rasterId) {
        RasterStats rasterStats = builtInOperatorDao.queryStats(rasterId);
        Double sum = rasterStats.sum;

        String mapAlgebraExpression = MapAlgebraUtil.generateProportionExpression(sum);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        rasterQuery.setFeature("proportion");
        rasterQuery.setAlgorithm("DZ_Proportion");
        rasterQuery.setMapAlgebraExpression(mapAlgebraExpression);

        builtInOperatorDao.singleMapAlgebra(rasterQuery);

        return rasterQuery.getId();
    }

    @Override
    public long DZ_Entropy(QueryMeta queryMeta, long rasterId) {
        RasterStats rasterStats = builtInOperatorDao.queryStats(rasterId);
        long count = rasterStats.count;

        String mapAlgebraExpression = MapAlgebraUtil.generateEntropyExpression(count);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);
        rasterQuery.setInputRasterId(rasterId);
        rasterQuery.setMapAlgebraExpression(mapAlgebraExpression);

        return builtInOperatorDao.entropy(rasterQuery);
    }

    @Override
    public long DZ_Weight(QueryMeta queryMeta, long[] entropy) {
        double numberOfIndex = entropy.length;// 指标个数
        double[] trueEntropy = Arrays.stream(entropy).mapToDouble(e -> (double) e / 1000000.0).toArray();
        return (long) (1000000 * (1.0 - trueEntropy[0])
                /
                (numberOfIndex - Arrays.stream(trueEntropy).sum()));
    }

    @Override
    public long DZ_RasterWeightSum(QueryMeta queryMeta, long[] args) {
        int n = args.length / 2;
        // 前两个栅格加权求和
        long rasterId = DZ_RasterWeightSum2(queryMeta, args[0], args[1], args[2], args[3]);
        for (int i = 2; i < n; i++) {// 第三个及之后的所有栅格
            rasterId = DZ_RasterWeightSum2(queryMeta, rasterId, 1, args[i * 2], args[i * 2 + 1]);
        }
        return rasterId;
    }

    @Override
    public long DZ_RasterMultiply2(QueryMeta queryMeta, long raster1, long raster2) {
        return 0;// todo
    }

    @Override
    public long DZ_RasterWeightSum2(QueryMeta queryMeta, long raster1, long weight1, long raster2, long weight2) {
        String mapAlgebraExpression = MapAlgebraUtil.generateWeightSumExpression(weight1, weight2);

        RasterQuery rasterQuery = new RasterQuery(queryMeta.workingAreaId, queryMeta.userId);

        rasterQuery.setInputRasterId(raster1);
        rasterQuery.setInputRasterId2(raster2);

        rasterQuery.setFeature("weightSum");
        rasterQuery.setAlgorithm("DZ_RasterWeightSum");

        rasterQuery.setMapAlgebraExpression(mapAlgebraExpression);

        builtInOperatorDao.weightSum(rasterQuery);

        return rasterQuery.id;
    }
}
