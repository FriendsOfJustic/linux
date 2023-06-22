package com.rsgisai.geohazard.level.vo;

import lombok.Data;

/**
 * @author tfh, created at 2023-02-16 4:54 PM
 */
@Data
public class RasterQueryVo {
    public Long id;
    /**
     * supported feature:
     * dem slope aspect curvature
     * dem_reclassify slope_reclassify aspect_reclassify curvature_reclassify
     */
    public String feature;
    public Long workingAreaId;
    public Integer numberClasses;
    public String format;


    // for evaluation only
    public Integer demNumberClasses;
    public Integer slopeNumberClasses;
    public Integer aspectNumberClasses;
    public Integer curvatureNumberClasses;
    public Integer outNumberClasses;
}
