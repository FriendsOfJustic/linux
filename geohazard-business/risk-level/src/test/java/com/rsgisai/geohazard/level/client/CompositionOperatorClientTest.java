package com.rsgisai.geohazard.level.client;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.system.common.R;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-04-07 4:33 PM
 */
@SpringBootTest
class CompositionOperatorClientTest {

    @Autowired
    CompositionOperatorClient compositionOperatorClient;

    @Test
    void getGhdsl() throws InterruptedException {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_Susceptibility";

        R<CompositionOperator> ghdsl = compositionOperatorClient.getGhdsl(compositionOperator.name);
        System.out.println("ghdsl = " + ghdsl);
    }
}