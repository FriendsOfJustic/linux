package com.rsgisai.geohazard.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class WorkingArea {
    private Integer id;
    private String name;
    private String wkt;
    private String geoJson;

    public WorkingArea(String name) {
        this.name = name;
    }
}
