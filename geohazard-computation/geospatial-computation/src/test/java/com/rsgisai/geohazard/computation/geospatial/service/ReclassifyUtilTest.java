package com.rsgisai.geohazard.computation.geospatial.service;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-03-06 10:02 PM
 */
class ReclassifyUtilTest {

    @Test
    void generateReclassexpr() {
        String s = ReclassifyUtil.generateReclassexpr(5, 0, 45);
        System.out.println("s = " + s);
    }

    @Test
    void generateAspectReclassexpr() {
        String s = ReclassifyUtil.generateAspectReclassexpr(5);
        System.out.println("s = " + s);
    }
}