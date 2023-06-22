package com.rsgisai.geohazard.level.entity;

import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import lombok.Data;

/**
 * @author tfh, created at 2023-02-16 4:54 PM
 */
@Data
public class RasterDaoParam {
    /**
     * supported feature:
     * dem slope aspect curvature
     * dem_reclassify slope_reclassify aspect_reclassify curvature_reclassify
     */
    private String feature;
    private Long workingAreaId;
    private Integer numberClasses;
    private String schema;
    private String table;



    public RasterDaoParam() {
    }

    public RasterDaoParam(
            String feature,
            Long workingAreaId,
            Integer numberClasses
    ) {
        this.feature = feature;
        this.workingAreaId = workingAreaId;
        this.numberClasses = numberClasses;
        this.schema = parseSchema(feature);
        this.table = feature;
    }

    public RasterDaoParam(RasterQueryVo rasterQueryVo) {
        this.feature = rasterQueryVo.getFeature();
        this.workingAreaId = rasterQueryVo.getWorkingAreaId();
        this.numberClasses = rasterQueryVo.getNumberClasses();
        this.schema = parseSchema(rasterQueryVo);
        this.table = feature;
    }

    public String parseSchema(String feature) {
        switch (feature) {
            case "dem":
                return "public";
            case "slope":
            case "aspect":
            case "curvature":

            case "dem_reclassify":
            case "slope_reclassify":
            case "aspect_reclassify":
            case "curvature_reclassify":

            case "dem_xxl":
            case "slope_xxl":
            case "aspect_xxl":
            case "curvature_xxl":
            case "evaluation":
                return "susceptibility";
            default:
                throw new RuntimeException("feature:" + feature + " not supported.");
        }
    }

    public String parseSchema(RasterQueryVo rasterQueryVo) {
        return parseSchema(rasterQueryVo.getFeature());
    }
}
