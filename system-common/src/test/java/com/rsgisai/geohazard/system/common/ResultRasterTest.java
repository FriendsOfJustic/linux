package com.rsgisai.geohazard.system.common;

import org.junit.jupiter.api.Test;

import java.util.TreeMap;

/**
 * @author tfh, created at 2023-04-13 9:36 AM
 */
class ResultRasterTest {

    @Test
    void setArgsJson() {
        ResultRaster resultRaster = new ResultRaster();
        resultRaster.arguments = new TreeMap<String, Object>() {{
            put("demNumberClasses", 12);
            put("module", "AHP");
        }};

        System.out.println("resultRaster = " + resultRaster);

        System.out.println(resultRaster.calculateAlgorithmArgs());
    }
}