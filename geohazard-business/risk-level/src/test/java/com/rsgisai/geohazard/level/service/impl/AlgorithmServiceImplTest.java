package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.dao.pgsql.AlgorithmDao;
import com.rsgisai.geohazard.level.entity.RasterStats;
import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;
import com.rsgisai.geohazard.level.service.AlgorithmService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.IOException;

@SpringBootTest
class AlgorithmServiceImplTest {
    @Autowired
    AlgorithmService algorithmService;
    @Autowired
    AlgorithmDao algorithmDao;

    @Test
    void reclassifyDem() throws SusceptibilityAlgorithmException {
        algorithmService.reclassify(2, "dem", 4);
    }

    @Test
    void generateXxlInRaster() throws SusceptibilityAlgorithmException, IOException {
        algorithmService.generateXxlInRaster(2, 18);
    }


    //    slope test
    @Test
    void reclassifySlope() throws SusceptibilityAlgorithmException {
        algorithmService.reclassify(2, "slope", 4);
    }

    @Test
    void slopeXxl() throws SusceptibilityAlgorithmException, IOException {
        int i = algorithmService.slopeXxlRasterGenerate(2, 4);
        System.out.println("i = " + i);
    }

    //    aspect test
    @Test
    void reclassifyAspect() throws SusceptibilityAlgorithmException {
        algorithmService.reclassify(2, "aspect", 4);
    }

    @Test
    void aspectXxl() throws SusceptibilityAlgorithmException, IOException {
        int i = algorithmService.aspectXxlRasterGenerate(2, 4);
        System.out.println("i = " + i);
    }
    //    curvature test
    @Test
    void reclassifyCurvature() throws SusceptibilityAlgorithmException {
        algorithmService.reclassify(2, "curvature", 4);
    }

    @Test
    void curvatureXxl() throws SusceptibilityAlgorithmException, IOException {
        int i = algorithmService.curvatureXxlRasterGenerate(2, 4);
        System.out.println("i = " + i);
    }

    @Test
    void generateReclassexpr() {
        RasterStats stats = algorithmDao.getStats(2L, 5);
        for (int i = 5; i < 11; i++) {
            String s = algorithmService.generateReclassexpr(i, stats.getMin(), stats.getMax());
            System.out.println("s = " + s);
        }

    }
}