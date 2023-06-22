package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.service.impl.AspectAlgorithm;
import org.junit.jupiter.api.Test;

/**
 * @author tfh, created at 2023-02-14 11:59 PM
 */
class AspectAlgorithmTest {

    @Test
    void generateReclassexpr() {
        AspectAlgorithm aspectAlgorithm = new AspectAlgorithm();
        for (int i = 3; i < 10; i++) {
            String s = aspectAlgorithm.generateReclassexpr(i);
            System.out.println(i + " = " + s);
        }
    }
}