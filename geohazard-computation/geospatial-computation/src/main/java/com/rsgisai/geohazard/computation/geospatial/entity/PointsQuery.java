package com.rsgisai.geohazard.computation.geospatial.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-03-12 9:55 AM
 */
@Data
public class PointsQuery {
    public PointsQuery(Long workingAreaId, Long userId) {
        this.workingAreaId = workingAreaId;
        this.userId = userId;
    }

    private Long id;
    private Long workingAreaId;
    private Long userId;
    private String feature;
}
