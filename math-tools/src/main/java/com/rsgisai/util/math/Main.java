package com.rsgisai.util.math;

import java.io.IOException;
import java.util.List;
import java.util.Map;

/**
 * @author tfh, created at 2023-05-25 4:10 PM
 */
public class Main {
    public static void main(String[] args) throws IOException {
        XLSParser xlsParser = new XLSParser();
        List<Map<String, Double>> maps = xlsParser.parseXLS("D:\\Repository\\Projects\\RERSSIL\\geohazard\\geohazard-gis\\algorithm\\landslide_demo.xls");
        for (Map<String, Double> map : maps) {
            System.out.println("map = " + map);
        }
    }
}