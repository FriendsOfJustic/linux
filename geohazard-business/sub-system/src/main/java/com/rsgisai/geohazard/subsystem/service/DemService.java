package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import org.springframework.web.multipart.MultipartFile;

/**
 * @author tfh, created at 2023-02-17 8:23 AM
 */
public interface DemService {
    RasterRecord save(long workingAreaId, MultipartFile geotiff);
}
