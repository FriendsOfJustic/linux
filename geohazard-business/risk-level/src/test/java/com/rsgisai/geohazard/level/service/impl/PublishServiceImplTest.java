package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.IOException;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-02-20 9:23 AM
 */
@SpringBootTest
class PublishServiceImplTest {

    @Autowired
    PublishServiceImpl publishService;


    @Test
    void publishRaster() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "dem_reclassify";
        rasterQueryVo.workingAreaId = 2L;
        rasterQueryVo.numberClasses = 8;
//        rasterQueryVo.format = "geotiff";
        publishService.publishRaster(rasterQueryVo);
    }
    @Test
    void setStyle(){
    }

    @Test
    void publishOriginRasterDem() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "dem";
        rasterQueryVo.workingAreaId = 1L;

        publishService.publishOriginRaster(rasterQueryVo);
    }

    @Test
    void publishOriginRasterPrecipitation() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "precipitation";
        rasterQueryVo.workingAreaId = 1L;

        publishService.publishOriginRaster(rasterQueryVo);
    }

    @Test
    void publishOriginRasterPopulation() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "population";
        rasterQueryVo.workingAreaId = 1L;

        publishService.publishOriginRaster(rasterQueryVo);
    }

    @Test
    void publishOriginRasterCrop() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "crop";
        rasterQueryVo.workingAreaId = 1L;

        publishService.publishOriginRaster(rasterQueryVo);
    }
    @Test
    void publishOriginRasterRoad() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "road";
        rasterQueryVo.workingAreaId = 1L;

        publishService.publishOriginRaster(rasterQueryVo);
    }

    @Test
    void publishResultRasterDem() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "susceptibility";
        rasterQueryVo.workingAreaId = 1L;
        rasterQueryVo.numberClasses = 4;// 用于 style

        publishService.publishResultRaster(rasterQueryVo);
    }
    @Test
    void publishResultRasterVulnerability() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "vulnerability";
        rasterQueryVo.workingAreaId = 1L;
        rasterQueryVo.numberClasses = 5;// 用于 style

        publishService.publishResultRaster(rasterQueryVo);
    }

    @Test
    void publishResultRasterGeohazardProbability() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "geohazard_probability";
        rasterQueryVo.workingAreaId = 1L;
        rasterQueryVo.numberClasses = 5;// 用于 style

        publishService.publishResultRaster(rasterQueryVo);
    }
    @Test
    void publishResultRasterGeohazardRisk() throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "geohazard_risk";
        rasterQueryVo.workingAreaId = 1L;
        rasterQueryVo.numberClasses = 5;// 用于 style

        publishService.publishResultRaster(rasterQueryVo);
    }
}