package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-04-06 10:50 AM
 */
@SpringBootTest
class GeohazardComputationJobDaoTest {

    @Autowired
    private GeohazardComputationJobDao geohazardComputationJobDao;

    @Test
    void selectById() {
        GeohazardComputationJob geohazardComputationJob = geohazardComputationJobDao.selectById(1L);
        System.out.println("geohazardComputationJob = " + geohazardComputationJob);
        geohazardComputationJob = geohazardComputationJobDao.selectById(2L);
        System.out.println("geohazardComputationJob = " + geohazardComputationJob);
    }
}