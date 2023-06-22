package com.rsgisai.geohazard.computation.geospatial.service.impl;

import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.OriginRasterDao;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import com.rsgisai.geohazard.computation.geospatial.service.OriginRasterService;
import com.rsgisai.util.gis.raster.Rasters;
import com.rsgisai.util.gis.raster.RastersImpl;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;

/**
 * @author tfh, created at 2023-03-12 1:23 PM
 */
@Service
public class OriginRasterServiceImpl implements OriginRasterService {

    private final OriginRasterDao originRasterDao;
    private final Rasters rasters = new RastersImpl();

    public OriginRasterServiceImpl(@Qualifier("originRasterDao") OriginRasterDao originRasterDao) {
        this.originRasterDao = originRasterDao;
    }

    @Override
    public int upload(MultipartFile multipartFile, RasterQuery rasterQuery) throws IOException {
//        long workingAreaId = rasterQuery.workingAreaId;
//        long userId = rasterQuery.userId;
//        String feature = rasterQuery.feature;

        rasterQuery.wkbHex = rasters.geotiff2WkbHex(multipartFile);

        return originRasterDao.upload(rasterQuery);
    }
}
