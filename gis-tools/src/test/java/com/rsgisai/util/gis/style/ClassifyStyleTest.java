package com.rsgisai.util.gis.style;

import com.rsgisai.util.gis.util.geoserver.GeoserverStyleManager;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.util.List;

/**
 * @author tfh, created at 2023-02-20 10:41 AM
 */
class ClassifyStyleTest {
    ClassifyStyle classifyStyle = new ClassifyStyle();

    @Test
    void generateClassifySld() throws IOException {
        int n = 3;
//        for (int n = 3; n < 10; n++) {
        String styleName = "reclassify";
        String s = classifyStyle.generateClassifySld(styleName + "_" + n, n);
        System.out.println("s = " + s);
//        }
    }

    @Test
    void generateRgbHexList() {
        for (int n = 1; n <= 10; n++) {
            List<String> strings = classifyStyle.generateRgbHexList(n);
            System.out.println("strings = " + strings);
        }
    }

    @Test
    void generateAndUpload() throws IOException {
        GeoserverStyleManager geoserverStyleManager = new GeoserverStyleManager();
        for (int i = 0; i < 30; i++) {
            int I = i + 1;
            String styleName = "reclassify" + "_" + I;
            String sldBody = classifyStyle.generateClassifySld(styleName, I);
            geoserverStyleManager.publishStyle(sldBody, styleName);
        }
    }
}