package com.rsgisai.geohazard.computation.geospatial.service;

import java.util.ArrayList;

public class MapAlgebraUtil {

    //        '([rast] - 0.5) / (76.51380157470703 - 0.5)'
    public static String generateNormalizeExpression(double min, double max) {
        return String.format("([rast] - %f) / (%f - %f)", min, max, min);
    }

    public static String generateProportionExpression(Double sum) {
        return String.format("[rast] / %f", sum);
    }

    public static String generateEntropyExpression(long n) {
        double ln_n = Math.log(n);
        return String.format("CASE WHEN [rast] = 0 THEN 0 ELSE ( - ([rast] * ln([rast])) / %f) END", ln_n);
    }

    public static String generateWeightSumExpression(long weight1, long weight2) {
        return String.format("[rast1] * %f + [rast2] * %f", weight1 / 1000000.0, weight2 / 1000000.0);
    }

    public static String generateMultiplyExpression() {
        return "[rast1] * [rast2]";
    }

    public static String generateNormalizeClassifiedExpression(Double max) {
        return String.format("[rast] / %f", max);
    }
}
