package com.rsgisai.geohazard.level.entity;

import lombok.Data;

@Data
public class Landslide {
    private Integer id;
    private Double volume;
    private Double theta;
    private Double height;
}