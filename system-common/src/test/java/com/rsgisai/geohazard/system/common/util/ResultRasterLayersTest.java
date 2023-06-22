package com.rsgisai.geohazard.system.common.util;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-04-12 11:07 PM
 */
class ResultRasterLayersTest {

    @Test
    void hash() {
        String text = "Hello World! 你好，世界！";
        for (int i = 0; i < 10; i++) {
            text += text;
        }
        System.out.println("text = " + text);
        String hash = ResultRasterLayers.hash(text+"a");
        System.out.println("hash = " + hash);
    }
}