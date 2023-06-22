package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.entity.RasterStats;
import com.rsgisai.geohazard.level.service.impl.CurvatureAlgorithm;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class CurvatureAlgorithmDaoTest {

    @Autowired
    CurvatureAlgorithmDao curvatureAlgorithmDao;

    @Test
    void getStats() {
        RasterStats stats = curvatureAlgorithmDao.getStats(new RasterRecord(null, 2L));
        System.out.println("stats = " + stats);
    }

    @Test
    void reclassify() {

        long workingAreaId = 2L;
        int numberClasses = 4;
        CurvatureAlgorithm curvatureAlgorithm = new CurvatureAlgorithm();
        RasterStats stats = curvatureAlgorithmDao.getStats(new RasterRecord(null, workingAreaId));
        int reclassify = curvatureAlgorithmDao.reclassify(workingAreaId,
                curvatureAlgorithm.generateReclassexpr(numberClasses, stats.getMin(), stats.getMax()),
                numberClasses);
        System.out.println("reclassify = " + reclassify);
    }
}