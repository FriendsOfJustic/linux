package com.rsgisai.geohazard.data.service.impl;

import com.rsgisai.geohazard.data.service.ResultRasterService;
import com.rsgisai.geohazard.system.common.ResultRaster;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.IOException;
import java.util.TreeMap;


@SpringBootTest
class ResultRasterServiceTest {

    @Autowired
    ResultRasterService resultRasterService;

    @Test
    void publish() throws IOException {
        ResultRaster resultRaster = new ResultRaster();
        resultRaster.workingAreaId = 1L;
        resultRaster.feature = "susceptibility";
        resultRaster.algorithm = "GH_Susceptibility";
        resultRaster.arguments = new TreeMap<String, Object>() {
            {
                put("aspectNumberClasses", 7);
                put("demNumberClasses", 5);
                put("outNumberClasses", 4);
                put("slopeNumberClasses", 6);
            }
        };

        int publish = resultRasterService.publish(resultRaster);
        System.out.println("publish = " + publish);
    }
}