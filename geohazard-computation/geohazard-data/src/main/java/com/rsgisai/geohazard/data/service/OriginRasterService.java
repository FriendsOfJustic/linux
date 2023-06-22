package com.rsgisai.geohazard.data.service;

import com.rsgisai.geohazard.data.vo.RasterQuery;
import com.rsgisai.geohazard.system.common.OriginRaster;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

/**
 * @author tfh, created at 2023-04-10 10:22 AM
 */
public interface OriginRasterService {
    List<OriginRaster> query(OriginRaster originRaster);

    int publish(OriginRaster originRaster) throws IOException;

    long upload(MultipartFile multipartFile, RasterQuery rasterQuery) throws IOException;

}
