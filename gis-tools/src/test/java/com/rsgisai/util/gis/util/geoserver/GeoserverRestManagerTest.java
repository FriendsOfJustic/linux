package com.rsgisai.util.gis.util.geoserver;

import com.rsgisai.geohazard.system.common.config.GeohazardConfig;
import com.rsgisai.geohazard.system.common.config.GeoserverConfig;
import org.junit.jupiter.api.Test;

import java.io.IOException;

/**
 * @author tfh, created at 2023-04-13 9:26 PM
 */
class GeoserverRestManagerTest {
    GeoserverRestManager geoserverRestManager =
            new GeoserverRestManager(
                    GeoserverConfig.username,
                    GeoserverConfig.password,
                    GeoserverConfig.hostname,
                    GeoserverConfig.port
            );

    @Test
    void uploadGeoTiff() {
    }

    @Test
    void setLayerStyle() {

    }

    @Test
    void getStyleInfo() throws IOException {
        String styleJson = geoserverRestManager
                .getStyleInfo(GeohazardConfig.WORKSPACE, "susceptibility_4");
        System.out.println("styleJson = " + styleJson);

        styleJson = geoserverRestManager
                .getStyleInfo(GeohazardConfig.WORKSPACE, "non-exist-style");
        System.out.println("styleJson = " + styleJson);
    }
    @Test
    void styleExist() throws IOException {
        boolean exist = geoserverRestManager.styleExist(GeohazardConfig.WORKSPACE, "susceptibility_4");
        System.out.println("exist = " + exist);

        exist = geoserverRestManager.styleExist("non-exist-workspace", "susceptibility_4");
        System.out.println("exist = " + exist);

        exist = geoserverRestManager.styleExist(GeohazardConfig.WORKSPACE, "non-exist-style");
        System.out.println("exist = " + exist);
    }
}