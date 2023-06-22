package com.rsgisai.geohazard.computation.geospatial.entity;

import lombok.Data;

@Data
public class Landslide {
    private Integer id;
    private Double volume;
    private Double theta;
    private Double height;
}
