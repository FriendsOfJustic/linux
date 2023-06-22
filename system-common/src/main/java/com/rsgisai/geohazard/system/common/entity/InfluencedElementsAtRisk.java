package com.rsgisai.geohazard.system.common.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-05-05 10:00 AM
 */
@Data
public class InfluencedElementsAtRisk {
    private Long id;
    private String type;
    private String name;
    private Long workingAreaId;
    private Integer year;
    private String geojson;
    private Double area;
    private Boolean isAtRisk;
}
