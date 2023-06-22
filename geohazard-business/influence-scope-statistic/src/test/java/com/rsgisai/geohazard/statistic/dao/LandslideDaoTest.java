package com.rsgisai.geohazard.statistic.dao;

import com.rsgisai.geohazard.entity.Landslide;
import com.rsgisai.geohazard.statistic.dao.mysql.LandslideDao;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class LandslideDaoTest {

    @Autowired
    private LandslideDao landslideDao;

    @Test
    public void testSelectById() {
        Landslide landslide = landslideDao.selectById(90);
        System.out.println("landslide = " + landslide);
    }
}