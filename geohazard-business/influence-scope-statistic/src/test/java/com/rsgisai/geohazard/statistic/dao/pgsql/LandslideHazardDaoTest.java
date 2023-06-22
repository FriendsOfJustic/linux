package com.rsgisai.geohazard.statistic.dao.pgsql;

import com.rsgisai.geohazard.statistic.entity.LandslideHazard;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class LandslideHazardDaoTest {

    @Autowired
    private LandslideHazardDao landslideHazardDao;

    @Test
    void selectAll() {
        List<LandslideHazard> landslideHazardList = landslideHazardDao.selectAll();
        System.out.println("landslideHazardList = " + landslideHazardList);
    }
}