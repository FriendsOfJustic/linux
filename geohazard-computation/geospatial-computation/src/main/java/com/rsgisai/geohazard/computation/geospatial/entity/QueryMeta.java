package com.rsgisai.geohazard.computation.geospatial.entity;

import lombok.Data;

@Data
public class QueryMeta {
    public QueryMeta(Long workingAreaId, Long userId) {
        this.workingAreaId = workingAreaId;
        this.userId = userId;
    }

    public Long workingAreaId;
    public Long userId;
}
