package com.rsgisai.geohazard.system.common.util;

import com.rsgisai.geohazard.system.common.ResultRaster;

import java.util.TreeMap;

/**
 * @author tfh, created at 2023-04-12 9:47 PM
 */
class ResultRasterLayerTest {

    @org.junit.jupiter.api.Test
    void getLayerName() {
        ResultRaster resultRaster = new ResultRaster();
        resultRaster.id = 12L;
        resultRaster.workingAreaId = 1L;
        resultRaster.feature = "susceptibility";
        resultRaster.arguments = new TreeMap<String, Object>() {{
            put("demNumberClasses", 5);
            put("slopeNumberClasses", 6);
            put("aspectNumberClasses", 8);
            put("outNumberClasses", 4);
        }};

        System.out.println("resultRaster = " + resultRaster);
    }
}