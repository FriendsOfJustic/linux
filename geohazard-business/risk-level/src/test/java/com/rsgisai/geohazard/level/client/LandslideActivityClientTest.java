package com.rsgisai.geohazard.level.client;

import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.LinearModel;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-05-24 11:49 PM
 */
@SpringBootTest
class LandslideActivityClientTest {
    @Autowired
    LandslideActivityClient landslideActivityClient;

    @Test
    void train() {
        String path = "D:\\Repository\\Projects\\RERSSIL\\geohazard\\geohazard-gis\\algorithm\\landslide_demo.xls";
        R<LinearModel> train = landslideActivityClient.train(LandslideActivityClient.TrainArg.builder().path(path).build());
        System.out.println("train = " + train);
    }
}