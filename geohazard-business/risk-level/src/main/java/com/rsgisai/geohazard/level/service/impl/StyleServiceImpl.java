package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.service.StyleService;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import org.springframework.stereotype.Service;

/**
 * @author tfh, created at 2023-02-20 2:52 PM
 */
@Service
public class StyleServiceImpl implements StyleService {
    @Override
    public String parseStyleName(RasterQueryVo rasterQueryVo) {
        String feature = rasterQueryVo.feature;
        if (feature.endsWith("reclassify")) {
            return "reclassify_" + rasterQueryVo.numberClasses;
        }
        if (feature.endsWith("xxl")) {
            return "xxl";
        }
        switch (feature) {
            case "road":
                return "road";
            case "crop":
                return "crop";
            case "population":
                return "population";
            case "vulnerability":
                return "vulnerability" + "_" + rasterQueryVo.numberClasses;
            case "geohazard_probability":
                return "geohazard_probability" + "_" + rasterQueryVo.numberClasses;
            case "geohazard_risk":
                return "geohazard_risk" + "_" + rasterQueryVo.numberClasses;
            case "precipitation":
                return "precipitation";
            case "susceptibility":
                return "susceptibility_" + rasterQueryVo.numberClasses;
            case "dem":
                return "susceptibility_dem";
            case "slope":
                return "susceptibility_slope";
            case "aspect":
                return "susceptibility_aspect";
            case "curvature":
                return "susceptibility_curvature";
            case "evaluation": {
                return "susceptibility_evaluation_" + rasterQueryVo.outNumberClasses;
            }
            default:
                throw new RuntimeException("parse style name failed, not supported feature:" + rasterQueryVo.feature);
        }
    }
}
