package com.rsgisai.geohazard.computation.geospatial.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.rsgisai.geohazard.computation.geospatial.entity.QueryMeta;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;

import java.util.SortedMap;

public interface BuiltInOperatorService {


    long DZ_OriginRaster(QueryMeta queryMeta, String feature);

    long DZ_ResultRaster(QueryMeta queryMeta, String feature);

    long DZ_OriginPoints(QueryMeta queryMeta, String feature);

    long DZ_Slope(QueryMeta queryMeta, long rasterId);

    long DZ_Aspect(QueryMeta queryMeta, long rasterId);

    /**
     * 等间距重分类
     *
     * @return
     */
    long DZ_EqualIntervalReclassify(QueryMeta queryMeta, long rasterId, Integer numberClasses);

    /**
     * 因为坡向有一个 -1 特殊的值，所以其重分类需要特殊对待
     *
     * @return
     */
    long DZ_AspectReclassify(QueryMeta queryMeta, long rasterId, Integer numberClasses);

    long DZ_InformationAmount(QueryMeta queryMeta, long reclassifyRaster, long points, Integer numberClasses);

    long DZ_RasterSum(QueryMeta queryMeta, long... rasterList);

    long DZ_RasterSum3(QueryMeta queryMeta, long raster1, long raster2, long raster3);
    long DZ_RasterSum5(QueryMeta queryMeta, long raster1, long raster2, long raster3, long raster4, long raster5);

    long DZ_SaveRaster(QueryMeta queryMeta, long raster, String feature, String algorithm, Object[] args);

    long SaveRaster(QueryMeta queryMeta, long raster, String feature, String algorithm,
                    SortedMap<String, Object> args) throws JsonProcessingException;

    /**
     * 对输入的 raster 归一化，令其值为 [0, 1]
     */
    long DZ_Normalize(QueryMeta queryMeta, long raster);
    long DZ_NormalizeClassified(QueryMeta queryMeta, long raster);

    /**
     * 待测试
     */
    long DZ_Proportion(QueryMeta queryMeta, long rasterId);
    long DZ_Entropy(QueryMeta queryMeta, long rasterId);
    long DZ_Weight(QueryMeta queryMeta, long[] entropy);

    /**
     * @param args 格式：raster1, weight1, raster2, weight2, ..., rasterN, weightN
     * @return
     */
    long DZ_RasterWeightSum(QueryMeta queryMeta, long[] args);
    // 双栅格地图代数算子
    long DZ_RasterMultiply2(QueryMeta queryMeta, long raster1, long raster2);

    long DZ_RasterWeightSum2(QueryMeta queryMeta, long raster1, long weight1, long raster2, long weight2);
}
