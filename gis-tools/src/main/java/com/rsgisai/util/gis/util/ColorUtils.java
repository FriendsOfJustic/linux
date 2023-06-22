package com.rsgisai.util.gis.util;

import java.awt.*;

/**
 * @author tfh, created at 2023-02-20 11:28 AM
 */
public class ColorUtils {


    /**
     * @param hue        0 - 360
     * @param saturation 0 - 1
     * @param value      0 - 1
     * @return #RRGGBB
     */
    public static String getRgbHex(float hue, float saturation, float value) {
        Color color = Color.getHSBColor(hue / 360.0f, saturation, value);
        int red = color.getRed();
        int green = color.getGreen();
        int blue = color.getBlue();
        return String.format("#%02X%02X%02X", red, green, blue);
    }
}
