package com.rsgisai.geohazard.data.vo;

import lombok.Data;

@Data
public class RasterQuery {
    public String algorithm;// optional
    public String algorithmArgs;// optional

    public RasterQuery(String feature, Long workingAreaId, Integer year, Long userId) {
        this.feature = feature;
        this.workingAreaId = workingAreaId;
        this.year = year;
        this.userId = userId;
    }

    public Long id;
    public Long workingAreaId;
    public Integer year;
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
