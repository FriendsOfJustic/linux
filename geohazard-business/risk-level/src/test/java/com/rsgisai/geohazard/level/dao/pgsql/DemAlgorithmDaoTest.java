package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.level.entity.Xxl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
class DemAlgorithmDaoTest {

    @Autowired
    DemAlgorithmDao demAlgorithmDao;

    @Test
    void getXxl() {
        List<Xxl> xxl = demAlgorithmDao.getXxlMapping(2, 5);
        System.out.println("xxl = " + xxl);
    }
    @Test
    void getXxlMapping(){
        List<Xxl> xxlMapping = demAlgorithmDao.getXxlMapping(2, 18);
        for (Xxl xxl : xxlMapping) {
            System.out.println("xxl = " + xxl);
        }
    }
}