package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.vo.RasterQueryVo;

/**
 * @author tfh, created at 2023-02-16 5:00 PM
 */
public interface RasterService {

    /**
     * supported raster:
     * table name                              | constraint
     * -----------------------------------------------
     * public.dem                              | workingAreaId
     * susceptibility.slope                    | workingAreaId
     * susceptibility.aspect                   | workingAreaId
     * susceptibility.curvature                | workingAreaId
     * ----
     * susceptibility.slope_reclassify         | workingAreaId, numberClasses
     * susceptibility.aspect_reclassify        | workingAreaId, numberClasses
     * susceptibility.curvature_reclassify     | workingAreaId, numberClasses
     */
    byte[] getRasterInputStream(RasterQueryVo rasterQueryVo);

    byte[] getEvaluationInputStream(RasterQueryVo rasterQueryVo);

    String[] rasterList = {
            "dem",
            "slope",
            "aspect",
            "curvature",

            "dem_reclassify",
            "slope_reclassify",
            "aspect_reclassify",
            "curvature_reclassify",

            "dem_xxl",
            "slope_xxl",
            "aspect_xxl",
            "curvature_xxl",
            "evaluation",
    };

    byte[] getXxlAllInputStream(RasterQueryVo rasterQueryVo);
}
