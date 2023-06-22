package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class SlopeDaoTest {

    @Autowired
    SlopeDao slopeDao;

    @Test
    void calculate() {
        RasterQuery rasterQuery = new RasterQuery(2L, 8L);
        int n = slopeDao.calculate(rasterQuery);
        System.out.println("n = " + n);
        System.out.println("rasterQuery = " + rasterQuery);

    }
}