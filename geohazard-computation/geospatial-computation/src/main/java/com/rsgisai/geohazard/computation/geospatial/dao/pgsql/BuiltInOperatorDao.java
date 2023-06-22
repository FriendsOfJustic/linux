package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.PointsQuery;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterStats;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

/**
 * @author tfh, created at 2023-03-06 8:01 PM
 */
@Mapper
@Repository
public interface BuiltInOperatorDao {
    /**
     * copy from origin_raster to intermediate_raster, for subsequence operations
     *
     * @param rasterQuery
     */
    int prepareRaster(RasterQuery rasterQuery);
    int preparePoints(PointsQuery pointsQuery);

    int calculateSlope(RasterQuery rasterQuery);
    int calculateAspect(RasterQuery rasterQuery);

    int reclassify(RasterQuery rasterQuery);

    RasterStats queryStats(long rasterId);

    int saveRaster(RasterQuery rasterQuery);

    void singleMapAlgebra(RasterQuery rasterQuery);

    long entropy(RasterQuery rasterQuery);

    int weightSum(RasterQuery rasterQuery);
    int overlap(RasterQuery rasterQuery);

    /**
     * 获取最新的 result raster（同一个算法可以有不同参数得到的结果）
     * @param rasterQuery
     * @return
     */
    int prepareResultRaster(RasterQuery rasterQuery);
}
