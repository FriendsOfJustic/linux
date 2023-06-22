package com.rsgisai.util.gis;

import org.junit.jupiter.api.Test;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.net.URL;

import static org.junit.jupiter.api.Assertions.*;

class ShapeFilesTest {

    @Test
    void toWktSinglePolygon() throws URISyntaxException, util.gis.exception.SinglePolygonException, IOException {
        // 注意不可以通过.getClass().getResource() 必须通过 ClassLoader 否则无法读取到 test/resources 里面的文件
        URL resource = this.getClass().getClassLoader().getResource("interest_demo/interest_demo.shp");
        File file = new File(resource.toURI());
        String s = ShapeFiles.toWktSinglePolygon(file);
        System.out.println(s);
        assert s.equals("POLYGON ((114.20481981121065 30.63628721535349, 114.2123940252626 30.671633547595434, 114.24616239624379 30.678734373269037, 114.26572911587766 30.666741867686824, 114.246951376874 30.626188263284234, 114.20481981121065 30.63628721535349))");
    }
}