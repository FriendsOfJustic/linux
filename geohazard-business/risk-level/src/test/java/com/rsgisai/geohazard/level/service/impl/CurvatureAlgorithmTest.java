package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.dao.pgsql.CurvatureAlgorithmDao;
import com.rsgisai.geohazard.level.entity.RasterStats;
import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class CurvatureAlgorithmTest {
    @Autowired
    CurvatureAlgorithmDao curvatureAlgorithmDao;

    @Test
    void reclassify() throws SusceptibilityAlgorithmException {
        RasterStats stats = curvatureAlgorithmDao.getStats(new RasterRecord(null, 2L));
        System.out.println("stats = " + stats);
        CurvatureAlgorithm curvatureAlgorithm = new CurvatureAlgorithm();
        for (int numberClasses = 5; numberClasses <= 10; numberClasses++) {
            String reclassexpr = curvatureAlgorithm.generateReclassexpr(numberClasses, stats.getMin(), stats.getMax());
            System.out.println("reclassexpr = " + reclassexpr);
        }
    }
}