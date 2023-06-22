package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.vo.RasterQueryVo;

import java.io.IOException;

/**
 * @author tfh, created at 2023-02-20 9:07 AM
 */
public interface PublishService {
//    void publishRaster(String slope, long workingAreaId, int numberClasses) throws IOException;

    void publishRaster(String feature, long workingAreaId, Integer numberClasses) throws IOException;

    /**
     * 发布除了 Evaluation 之外的所有其他图层
     * @param rasterQueryVo
     * @throws IOException
     */
    void publishRaster(RasterQueryVo rasterQueryVo) throws IOException;

    void publishEvaluation(RasterQueryVo rasterQueryVo) throws IOException;

    void publishDemReclassifyRaster(long workingAreaId, int numberClasses) throws IOException;

    void publishEvaluation(long workingAreaId, Integer demNumberClasses, Integer slopeNumberClasses, Integer aspectNumberClasses, Integer curvatureNumberClasses, Integer outNumClass) throws IOException;

    void publishSusceptibility(long workingAreaId, Integer outNumberClasses, Integer demNumberClasses, Integer slopeNumberClasses, Integer aspectNumberClasses, Integer curvatureNumberClasses) throws IOException;

    void publishOriginRaster(RasterQueryVo rasterQueryVo) throws IOException;

    void publishResultRaster(RasterQueryVo rasterQueryVo) throws IOException;

}
