package com.rsgisai.geohazard.level.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.rsgisai.geohazard.level.dao.pgsql.LandslidePotentialDao;
import com.rsgisai.geohazard.level.entity.LandslidePotential;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-06-07 10:06 PM
 */
@SpringBootTest
class LandslideActivityServiceTest {
    @Autowired
    LandslideActivityService landslideActivityService;
    @Qualifier("landslidePotentialDao")
    @Autowired
    private LandslidePotentialDao landslidePotentialDao;

    @Test
    void evaluate() throws JsonProcessingException {
        LandslidePotential evaluate = landslideActivityService.evaluate("53011301091R");
        System.out.println("evaluate = " + evaluate);
    }

    @Test
    void all() throws JsonProcessingException {
        List<LandslidePotential> landslidePotentials = landslidePotentialDao.selectAll();
        for (LandslidePotential landslidePotential : landslidePotentials) {
            LandslidePotential evaluate = landslideActivityService.evaluate(landslidePotential.getNo());
            System.out.println("evaluate = " + evaluate);
        }
    }
}