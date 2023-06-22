package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class AspectDaoTest {

    @Autowired
    AspectDao aspectDao;

    @Test
    void calculate() {
        RasterQuery rasterQuery = new RasterQuery(2L, 8L);
        int n = aspectDao.calculate(rasterQuery);
        System.out.println("n = " + n);
        System.out.println("rasterQuery = " + rasterQuery);

    }
}