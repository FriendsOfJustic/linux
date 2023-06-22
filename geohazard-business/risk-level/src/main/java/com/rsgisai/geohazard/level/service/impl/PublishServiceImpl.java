package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.dao.pgsql.EvaluationAlgorithmDao;
import com.rsgisai.geohazard.level.dao.pgsql.RasterDao;
import com.rsgisai.geohazard.level.entity.RasterDaoParam;
import com.rsgisai.geohazard.level.service.PublishService;
import com.rsgisai.geohazard.level.service.StyleService;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import com.rsgisai.util.gis.util.geoserver.GeoserverRestManager;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * @author tfh, created at 2023-02-20 9:08 AM
 */
@Service
public class PublishServiceImpl implements PublishService {
    private final RasterDao rasterDao;
    private final EvaluationAlgorithmDao evaluationAlgorithmDao;
    private final StyleService styleService;
    GeoserverRestManager geoserverManager = new GeoserverRestManager("admin", "geoserver", "www.rsgisai.com", 8080);

    public PublishServiceImpl(@Qualifier("rasterDao") RasterDao rasterDao, @Qualifier("evaluationAlgorithmDao") EvaluationAlgorithmDao evaluationAlgorithmDao, StyleService styleService) {
        this.rasterDao = rasterDao;
        this.evaluationAlgorithmDao = evaluationAlgorithmDao;
        this.styleService = styleService;
    }

//    @Override
//    public void publishRaster(String slope, long workingAreaId, int numberClasses) throws IOException {}

    @Override
    public void publishRaster(String feature, long workingAreaId, Integer numberClasses) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = feature;
        rasterQueryVo.workingAreaId = workingAreaId;
        rasterQueryVo.numberClasses = numberClasses;
        publishRaster(rasterQueryVo);
    }

    @Override
    public void publishRaster(RasterQueryVo rasterQueryVo) throws IOException {
        String feature = rasterQueryVo.getFeature();
        Long workingAreaId = rasterQueryVo.getWorkingAreaId();
        Integer numberClasses = rasterQueryVo.getNumberClasses();

        RasterDaoParam rasterDaoParam = new RasterDaoParam(rasterQueryVo);
        RasterRecord rasterRecord = rasterDao.fetchRaster(rasterDaoParam);
        byte[] rast = rasterRecord.getRast();

        InputStream inputStream = new ByteArrayInputStream(rast);
        String layerName =
                feature +
                        "_" + workingAreaId +
                        (numberClasses != null ? "_" + numberClasses : "");
        geoserverManager.uploadGeoTiff("geohazard", layerName, inputStream);
        inputStream.close();

        geoserverManager.setLayerStyle("geohazard", layerName,
                styleService.parseStyleName(rasterQueryVo));

    }

    @Override
    public void publishEvaluation(RasterQueryVo rasterQueryVo) throws IOException {
        String feature = rasterQueryVo.getFeature();
        Long workingAreaId = rasterQueryVo.getWorkingAreaId();

        RasterRecord rasterRecord = evaluationAlgorithmDao.fetchRaster(rasterQueryVo);
        byte[] rast = rasterRecord.getRast();

        InputStream inputStream = new ByteArrayInputStream(rast);
        String layerName = feature
                + "_" + workingAreaId
                + "_" + rasterQueryVo.outNumberClasses
                + "_" + rasterQueryVo.demNumberClasses
                + "_" + rasterQueryVo.slopeNumberClasses
                + "_" + rasterQueryVo.aspectNumberClasses
                + "_" + rasterQueryVo.curvatureNumberClasses;
        geoserverManager.uploadGeoTiff("geohazard", layerName, inputStream);
        inputStream.close();

        geoserverManager.setLayerStyle("geohazard", layerName,
                styleService.parseStyleName(rasterQueryVo));
    }

    @Override
    public void publishDemReclassifyRaster(long workingAreaId, int numberClasses) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "dem";
        rasterQueryVo.workingAreaId = workingAreaId;
        rasterQueryVo.numberClasses = numberClasses;
        publishRaster(rasterQueryVo);
    }

    @Override
    public void publishEvaluation(
            long workingAreaId,
            Integer demNumberClasses,
            Integer slopeNumberClasses,
            Integer aspectNumberClasses,
            Integer curvatureNumberClasses,
            Integer outNumberClasses
    ) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.feature = "evaluation";
        rasterQueryVo.workingAreaId = workingAreaId;
        rasterQueryVo.demNumberClasses = demNumberClasses;
        rasterQueryVo.slopeNumberClasses = slopeNumberClasses;
        rasterQueryVo.aspectNumberClasses = aspectNumberClasses;
        rasterQueryVo.curvatureNumberClasses = curvatureNumberClasses;
        rasterQueryVo.outNumberClasses = outNumberClasses;
        publishEvaluation(rasterQueryVo);
    }

    @Override
    public void publishSusceptibility(long workingAreaId, Integer outNumberClasses, Integer demNumberClasses, Integer slopeNumberClasses, Integer aspectNumberClasses, Integer curvatureNumberClasses) throws IOException {
        // publish dem slope aspect curvature
        String[] features = {"dem", "slope", "aspect", "curvature"};
        for (String feature : features) {
            publishRaster(feature, workingAreaId, null);
        }
        // publish reclassify
        publishRaster("dem_reclassify", workingAreaId, demNumberClasses);
        publishRaster("slope_reclassify", workingAreaId, slopeNumberClasses);
        publishRaster("aspect_reclassify", workingAreaId, aspectNumberClasses);
        publishRaster("curvature_reclassify", workingAreaId, curvatureNumberClasses);

        // publish xxl
        publishRaster("dem_xxl", workingAreaId, demNumberClasses);
        publishRaster("slope_xxl", workingAreaId, slopeNumberClasses);
        publishRaster("aspect_xxl", workingAreaId, aspectNumberClasses);
        publishRaster("curvature_xxl", workingAreaId, curvatureNumberClasses);

        // publish evaluation
        publishEvaluation(workingAreaId, demNumberClasses, slopeNumberClasses, aspectNumberClasses, curvatureNumberClasses, outNumberClasses);
    }

    @Override
    public void publishOriginRaster(RasterQueryVo rasterQueryVo) throws IOException {
        String feature = rasterQueryVo.getFeature();
        Long workingAreaId = rasterQueryVo.getWorkingAreaId();

        RasterRecord rasterRecord = rasterDao.fetchOriginRaster(rasterQueryVo);
        byte[] rast = rasterRecord.getRast();

        InputStream inputStream = new ByteArrayInputStream(rast);
        String layerName = feature + "_" + workingAreaId;
        geoserverManager.uploadGeoTiff("geohazard", layerName, inputStream);
        inputStream.close();

        geoserverManager.setLayerStyle("geohazard", layerName,
                styleService.parseStyleName(rasterQueryVo));
    }

    @Override
    public void publishResultRaster(RasterQueryVo rasterQueryVo) throws IOException {
        String feature = rasterQueryVo.getFeature();
        Long workingAreaId = rasterQueryVo.getWorkingAreaId();

        RasterRecord rasterRecord = rasterDao.fetchResultRaster(rasterQueryVo);
        byte[] rast = rasterRecord.getRast();

        InputStream inputStream = new ByteArrayInputStream(rast);
        String layerName = feature + "_" + workingAreaId;
        geoserverManager.uploadGeoTiff("geohazard", layerName, inputStream);
        inputStream.close();

        geoserverManager.setLayerStyle("geohazard", layerName,
                styleService.parseStyleName(rasterQueryVo));
    }
}
