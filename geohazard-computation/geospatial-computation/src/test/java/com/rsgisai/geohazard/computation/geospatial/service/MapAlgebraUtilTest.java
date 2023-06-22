package com.rsgisai.geohazard.computation.geospatial.service;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-03-16 9:12 PM
 */
class MapAlgebraUtilTest {

    @Test
    void generateNormalizeExpression() {
        String s = MapAlgebraUtil.generateNormalizeExpression(1, 76.5);
        System.out.println("s = " + s);
    }
}