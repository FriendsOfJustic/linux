package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.PointsQuery;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterStats;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-03-06 8:40 PM
 */
@SpringBootTest
class BuiltInOperatorDaoTest {
    @Autowired
    BuiltInOperatorDao builtInOperatorDao;

    @Test
    void prepareRaster() {
        RasterQuery rasterQuery = new RasterQuery(9L, 6L);
        rasterQuery.setFeature("dem");
        builtInOperatorDao.prepareRaster(rasterQuery);
        System.out.println("rasterQuery = " + rasterQuery);
    }
    @Test
    void preparePoints() {

        PointsQuery pointsQuery = new PointsQuery(1L, 6L);
        pointsQuery.setFeature("geohazard_potential");
        builtInOperatorDao.preparePoints(pointsQuery);
        System.out.println("pointsQuery = " + pointsQuery);

    }

    @Test
    void calculateSlope() {
        RasterQuery rasterQuery = new RasterQuery(9L, 8L);
        rasterQuery.setInputRasterId(9L);
        builtInOperatorDao.calculateSlope(rasterQuery);
        System.out.println("rasterQuery = " + rasterQuery);
    }

    @Test
    void calculateAspect() {
        RasterQuery rasterQuery = new RasterQuery(9L, 8L);
        rasterQuery.setInputRasterId(9L);
        builtInOperatorDao.calculateAspect(rasterQuery);
        System.out.println("rasterQuery = " + rasterQuery);
    }

    @Test
    void queryStats() {
        RasterStats rasterStats = builtInOperatorDao.queryStats(16);
        System.out.println("rasterStats = " + rasterStats);

        rasterStats = builtInOperatorDao.queryStats(14);
        System.out.println("rasterStats = " + rasterStats);
    }
}