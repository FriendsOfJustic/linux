package com.rsgisai.geohazard.computation.geospatial.entity;

import lombok.Data;

@Data
public class RasterQuery {
    public String algorithm;// optional
    public String algorithmArgs;// optional

    public RasterQuery(Long workingAreaId, Long userId) {
        this.workingAreaId = workingAreaId;
        this.userId = userId;
    }

    public Long id;
    public Long workingAreaId;
    public Long userId;
    public String feature;

    public Long inputRasterId;
    public Long inputPointsId;

    // for raster upload
    public String wkbHex;

    // for reclassify and information amount
    public Integer numberClasses;
    // for reclassify only
    public String reclassifyExpression;

    public Long inputRasterId2;

    // for MapAlgebra only
    public String mapAlgebraExpression;
}
