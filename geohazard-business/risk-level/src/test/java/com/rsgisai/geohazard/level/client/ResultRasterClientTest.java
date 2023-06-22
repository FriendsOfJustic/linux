package com.rsgisai.geohazard.level.client;

import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.ResultRaster;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-04-18 9:27 AM
 */
@SpringBootTest
class ResultRasterClientTest {

    @Autowired
    ResultRasterClient resultRasterClient;

    @Test
    void selectById() {
        R<ResultRaster> resultRasterR = resultRasterClient.selectById(44L);
        System.out.println("resultRasterR = " + resultRasterR);
    }
}