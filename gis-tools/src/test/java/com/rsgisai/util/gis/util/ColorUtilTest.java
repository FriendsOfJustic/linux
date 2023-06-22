package com.rsgisai.util.gis.util;

import org.junit.jupiter.api.Test;

import java.awt.*;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-02-20 11:04 AM
 */
class ColorUtilTest {


    @Test
    void hsvToRgb() {
    }

    @Test
    void hsvToRgbHex() {
//        float hue = 0; // 色相值
//        float hue = 120; // 色相值
        float hue = 240; // 色相值
        float saturation = 1f; // 饱和度值
        float value = 1f; // 值（亮度）值
        String rgb = ColorUtils.getRgbHex(hue, saturation, value);
        System.out.println("rgb = " + rgb);
    }
}