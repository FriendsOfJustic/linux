package com.rsgisai.geohazard.data.service.impl;

import com.rsgisai.geohazard.system.common.config.GeohazardConfig;
import com.rsgisai.geohazard.data.dao.pgsql.ResultRasterDao;
import com.rsgisai.geohazard.data.service.ResultRasterService;
import com.rsgisai.geohazard.system.common.ResultRaster;
import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.util.gis.util.geoserver.GeoserverRestManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;


//后端逻辑   在这里写
@Service
public class ResultRasterServiceImpl implements ResultRasterService {

    @Autowired
    private GeoserverRestManager geoserverManager;

    @Autowired
    private ResultRasterDao resultRasterDao;

    @Override
    public int publish(ResultRaster resultRaster) throws IOException {
        // 图层名称：可以根据需要自定义
        String layerName = resultRaster.calculateLayerName();

        resultRaster.calculateAlgorithmArgs();
        // 获取GeoTIFF字节序列，根据自己要发布的栅格所在的表修改对应的Mapper
        RasterRecord rasterRecord = resultRasterDao.fetchRasterTiff(resultRaster);
        byte[] rast = rasterRecord.getTiff();


        // publish
        InputStream inputStream = new ByteArrayInputStream(rast);
        geoserverManager.uploadGeoTiff(
                GeohazardConfig.WORKSPACE,// 项目默认工作空间，不需要改变
                layerName,// 自定义
                inputStream// 固定写法
        );
        inputStream.close();// 固定写法

        // update database; 更新数据库里面栅格对应GeoServer图层名称
        resultRasterDao.updateLayerName(
                rasterRecord.getId()/* resultRaster 里没有ID，需要从查询结果 rasterRecord 中获取ID*/,
                layerName);

        // 如果样式不存在则抛异常
        geoserverManager.setLayerStyle(
                GeohazardConfig.WORKSPACE,
                layerName,
                getStyleName(resultRaster)// 需要给此栅格指定一个GeoServer里面存在的Style
        );

        return 1;
    }

    private String getStyleName(ResultRaster resultRaster) {
        switch (resultRaster.feature) {
            case "susceptibility":
                return "susceptibility" + "_" + GeohazardConfig.SusceptibilityNumberOfClasses;
            case "probability":// same as geohazard_probability
                return "probability" + "_" + GeohazardConfig.ProbabilityNumberOfClasses;
            case "geohazard_probability":
                return "geohazard_probability" + "_" + GeohazardConfig.ProbabilityNumberOfClasses;
            default:
                throw new RuntimeException("to be implemented.");
        }
    }
}
