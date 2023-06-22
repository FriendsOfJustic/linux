package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.io.InputStream;

/**
 * @author tfh, created at 2023-03-12 1:23 PM
 */
public interface OriginRasterService {
    int upload(MultipartFile multipartFile, RasterQuery rasterQuery) throws IOException;
}
