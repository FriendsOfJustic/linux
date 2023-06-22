package com.rsgisai.geohazard.system.common;

import com.rsgisai.geohazard.system.common.config.GeoserverConfig;
import com.rsgisai.geohazard.system.common.exception.FeatureNotSupportedException;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * generateLayerName() 与 getLayerName() 区分，
 * generateLayerName() 用于利用 feature & workingAreaId 生成 layerName
 * getLayerName() 用于普通数据库映射
 *
 * @author tfh, created at 2023-04-10 10:21 AM
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class OriginRaster {
    Long id;
    Long workingAreaId;
    String feature;


    // geoserver 相关
    private String layerName;
    private String styleName;

    /**
     * 由
     * 1. String feature
     * 2. Long workingAreaId
     * 计算 layerName
     */
    public String generateLayerName() {
        if (feature == null) throw new RuntimeException("feature is needed for generate layer name.");
        if (workingAreaId == null) throw new RuntimeException("working area id is needed for generate layer name.");
        return feature
                + GeoserverConfig.LayerNameDELIMITER
                + workingAreaId;
    }

    public String generateStyleName() {
        switch (feature) {
            case "dem":
                return "dem" + GeoserverConfig.StyleNameDELIMITER + workingAreaId;
            default:
                throw new FeatureNotSupportedException(feature, "generate style name failed.");
       }
    }
}
