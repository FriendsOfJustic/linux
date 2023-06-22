package com.rsgisai.geohazard.system.common.entity;

import lombok.Data;



@Data
public class GeohazardRisk {
    private Long id;
    private Long workingAreaId;

    private byte[] rast;
    private Integer year;


    private Integer val;

    public GeohazardRisk() {

    }

    public GeohazardRisk(Long workingAreaId, Integer year) {
        this.year = year;
        this.workingAreaId = workingAreaId;
    }

}
