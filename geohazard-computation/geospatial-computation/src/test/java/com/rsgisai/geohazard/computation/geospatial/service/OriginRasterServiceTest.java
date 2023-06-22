package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.mock.web.MockMultipartFile;

import java.io.FileInputStream;
import java.io.IOException;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-03-12 1:52 PM
 */
@SpringBootTest
class OriginRasterServiceTest {

    @Autowired
    OriginRasterService originRasterService;

    @Test
    void uploadDC() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:/tmp/DEM.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("_.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "dem";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }

    @Test
    void upload() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:/tmp/aspect_reclassify9_.40.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "aspect_reclassify";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }

    @Test
    void uploadLandcover() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:/Data/Geohazard/dc_landcover/dc_landcover.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "landcover";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }

    @Test
    void uploadPopulation() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:\\Data\\Geohazard\\dong_chuan\\dc_population_density\\population.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "population";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }
    @Test
    void uploadCrop() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:\\Data\\Geohazard\\dong_chuan\\crop\\crop.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "crop";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }
    @Test
    void uploadVulnerability() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:\\Data\\Geohazard\\dong_chuan\\vulnerability\\vulnerability.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "vulnerability";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }
    @Test
    void uploadGeohazardRisk() throws IOException {
        FileInputStream contentStream = new FileInputStream("D:\\Data\\Geohazard\\dong_chuan\\geohazard_risk\\geohazard_risk.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "geohazard_risk";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }
    @Test
    void uploadRoad() throws IOException {
        FileInputStream contentStream =
                new FileInputStream("D:\\Data\\Geohazard\\dong_chuan\\road_raster\\road.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "road";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }

    /**
     * 上传正方形的降雨量
     */
    @Test
    void uploadPrecipitationRect() throws IOException {
        FileInputStream contentStream =
                new FileInputStream("D:\\Data\\Geohazard\\dong_chuan\\precipitation\\precipitation.tif");

        MockMultipartFile multipartFile = new MockMultipartFile("the_tif.tif", contentStream);

        RasterQuery rasterQuery = new RasterQuery(1L, 3L);
        rasterQuery.feature = "precipitation";

        int upload = originRasterService.upload(multipartFile, rasterQuery);
        System.out.println("upload = " + upload);
    }
}