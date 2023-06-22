package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.InformationAmount;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import com.rsgisai.geohazard.computation.geospatial.service.InformationAmountUtil;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-03-12 2:41 PM
 */
@SpringBootTest
class InformationAmountDaoTest {
    @Autowired
    InformationAmountDao informationAmountDao;

    @Test
    void calculateJoinCount() {
        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.numberClasses = 9;
        rasterQuery.feature = "aspect_reclassify";
        rasterQuery.inputRasterId = 44L;
        rasterQuery.inputPointsId = 2L;

        int i = informationAmountDao.clearJoinCount(rasterQuery);
        System.out.println("i = " + i);
        i = informationAmountDao.calculateJoinCount(rasterQuery);
        System.out.println("i = " + i);
    }
    @Test
    void calculateLevelCount() {
        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.numberClasses = 9;
        rasterQuery.feature = "aspect_reclassify";
        rasterQuery.inputRasterId = 44L;
//        rasterQuery.inputPointsId = 2L;

        int i = informationAmountDao.clearLevelCount(rasterQuery);
        System.out.println("i = " + i);
        i = informationAmountDao.calculateLevelCount(rasterQuery);
        System.out.println("i = " + i);
    }

    @Test
    void informationAmount(){
        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.numberClasses = 5;
        rasterQuery.feature = "aspect_reclassify";
//        rasterQuery.inputRasterId = 44L;
//        rasterQuery.inputPointsId = 2L;

        List<InformationAmount> informationAmountMapping = informationAmountDao.getInformationAmountMapping(rasterQuery);
        System.out.println("informationAmountMapping = " + informationAmountMapping);
        String s = InformationAmountUtil.generateXxlMappingExpression(informationAmountMapping, rasterQuery.numberClasses);
        System.out.println("s = " + s);
    }

}