package com.rsgisai.util.gis.util;

import com.rsgisai.util.gis.util.geoserver.GeoserverRestManager;
import org.junit.jupiter.api.Test;

import java.io.IOException;

/**
 * @author tfh, created at 2023-02-20 9:20 AM
 */
class GeoserverManagerTest {

    GeoserverRestManager geoserverManager = new GeoserverRestManager("admin", "geoserver", "www.rsgisai.com", 8080);

    @Test
    void setLayerStyle() throws IOException {
        String workspace = "geohazard";
        String feature = "dem_reclassify";
        Integer workingAreaId = 2;
        Integer numberClasses = 8;
        String layerName = workspace + ":" + feature
                + "_" + workingAreaId
                + (numberClasses != null ? "_" + numberClasses : "");
        geoserverManager.setLayerStyle(workspace, layerName,
                feature + (numberClasses != null ? "_" + numberClasses : ""));
    }
}