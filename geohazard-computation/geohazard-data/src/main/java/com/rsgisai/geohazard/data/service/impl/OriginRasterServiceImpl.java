package com.rsgisai.geohazard.data.service.impl;

import com.rsgisai.geohazard.data.dao.pgsql.OriginRasterDao;
import com.rsgisai.geohazard.data.service.OriginRasterService;
import com.rsgisai.geohazard.data.vo.RasterQuery;
import com.rsgisai.geohazard.system.common.OriginRaster;
import com.rsgisai.geohazard.system.common.config.GeohazardConfig;
import com.rsgisai.util.gis.raster.Rasters;
import com.rsgisai.util.gis.raster.RastersImpl;
import com.rsgisai.util.gis.util.geoserver.GeoserverRestManager;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.List;

/**
 * @author tfh, created at 2023-04-10 10:22 AM
 */
@Slf4j
@Service
public class OriginRasterServiceImpl implements OriginRasterService {
    @Autowired
    private OriginRasterDao originRasterDao;
    @Autowired
    private GeoserverRestManager geoserverManager;

    @Override
    public List<OriginRaster> query(OriginRaster originRaster) {
        return originRasterDao.select(originRaster);
    }

    @Override
    public int publish(OriginRaster originRaster) throws IOException {

        byte[] rast = originRasterDao.fetchRasterTiff(originRaster).getTiff();

        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(rast);
        String layerName = originRaster.generateLayerName();
        geoserverManager.uploadGeoTiff(
                GeohazardConfig.WORKSPACE,
                layerName,
                byteArrayInputStream
        );
        byteArrayInputStream.close();
        log.info("layer:{} uploaded to geoserver.", layerName);

        // 如果样式不存在则抛异常
        String styleName = originRaster.generateStyleName();
        geoserverManager.setLayerStyle(
                GeohazardConfig.WORKSPACE,
                layerName,
                styleName
        );
        log.info("{} published with style:{}", layerName, styleName);

        return 1;
    }

    private final Rasters rasters = new RastersImpl();

    public OriginRasterServiceImpl(@Qualifier("originRasterDao") OriginRasterDao originRasterDao) {
        this.originRasterDao = originRasterDao;
    }

    @Override
    public long upload(MultipartFile multipartFile, RasterQuery rasterQuery) throws IOException {
//        long workingAreaId = rasterQuery.workingAreaId;
//        long userId = rasterQuery.userId;
//        String feature = rasterQuery.feature;

        rasterQuery.wkbHex = rasters.geotiff2WkbHex(multipartFile);

        return originRasterDao.upload(rasterQuery);
    }
}
