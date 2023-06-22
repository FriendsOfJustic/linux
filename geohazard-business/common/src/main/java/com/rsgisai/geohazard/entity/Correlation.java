package com.rsgisai.geohazard.entity;

import lombok.Data;

import java.util.ArrayList;
import java.util.List;

@Data
public class Correlation {
    private static List<String> staticNames = new ArrayList<String>() {{
        add("volume");
        add("theta");
        add("height");
    }};
    private final List<String> names = staticNames;
    private List<Boolean> validList;

    private List<List<Double>> matrix;

}
