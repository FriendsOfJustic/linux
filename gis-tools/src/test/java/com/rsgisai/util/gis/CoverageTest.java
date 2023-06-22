package com.rsgisai.util.gis;

import com.rsgisai.util.gis.util.geoserver.GeoserverRestManager;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * @author tfh, created at 2023-02-16 3:09 PM
 */
public class CoverageTest {
    String hostname = "www.rsgisai.com";
    int port = 8080;
    String username = "admin";
    String password = "geoserver";
    GeoserverRestManager geoserverManager = new GeoserverRestManager(username, password, hostname, port);

    @Test
    void upload() throws IOException {
        String layerName = "dem103";
        String workspace = "geohazard";
        String demFilePath = "D:\\tmp\\dem.2.tif";
//        String demFilePath = "D:\\tmp\\curvature.2.tif";

        InputStream inputStream = Files.newInputStream(Paths.get(demFilePath));

        String response = geoserverManager.uploadGeoTiff(workspace, layerName, inputStream);
        System.out.println(response);
    }
}
