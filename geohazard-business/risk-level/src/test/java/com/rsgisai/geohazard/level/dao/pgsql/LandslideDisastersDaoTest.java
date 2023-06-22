package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.GeohazardRisk;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class LandslideDisastersDaoTest {
    @Autowired
    private LandslideDisastersDao landslideDisastersDao;


    //  测试--通过危险性和易损性的组合得到风险等级，将其插入geohazard_risk表中
    @Test
    void insertRisk(){
        GeohazardRisk geohazardRisk = new GeohazardRisk();
        geohazardRisk.setWorkingAreaId(1L);
        geohazardRisk.setYear(2022);
        System.out.println(landslideDisastersDao.insertRisk(geohazardRisk));
    }

    // 区域风险等级评价
    @Test
    void selectRast(){
        GeohazardRisk geohazardRisk = new GeohazardRisk();
        geohazardRisk.setWorkingAreaId(7L);
        geohazardRisk.setYear(2022);
        System.out.println(landslideDisastersDao.selectRast(geohazardRisk));
    }

    // 单体风险等级评价
    @Test
    void selectValues1(){
        GeohazardRisk geohazardRisk = new GeohazardRisk();
        geohazardRisk.setWorkingAreaId(7L);
        geohazardRisk.setYear(2022);
        System.out.println(landslideDisastersDao.selectValues1(geohazardRisk));
    }
}



