package com.rsgisai.geohazard.system.common.entity;


import lombok.Data;

/*
     created at 2023-05-17 9:04 AM
     通过表InflunceArea创建
 */

@Data
public class InfluenceArea {
    private Integer id;
    private Long workingAreaId;
    private Double area;

    private byte[] geom;
    private Long tergetRegionId;
}
