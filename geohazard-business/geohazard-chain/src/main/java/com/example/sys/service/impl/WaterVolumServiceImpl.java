package com.example.sys.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.example.sys.entity.WaterVolume;
import com.example.sys.geoserver.GeoserverRestManager;
import com.example.sys.mapper.WaterVolumMapper;
import com.example.sys.service.IWaterVolumeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigDecimal;
import java.math.BigInteger;

@Service
public class WaterVolumServiceImpl extends ServiceImpl<WaterVolumMapper, WaterVolume> implements IWaterVolumeService {

    @Autowired
    private WaterVolumMapper waterVolumMapper;


    @Autowired
    GeoserverRestManager geoserverRestManager;


    //算法的核心计算公式：(num*水面高程-sum(水底dem)) * 矢量的面积
    //化简后的计算式为： 水面高程*水域的面积-水底dem总和*每个栅格的面积
    @Override
    public BigDecimal WaterVolumeAlgorithm(double water_level) throws IOException {
//        //计算像素的数量
//        BigDecimal num=waterVolumMapper.selectNum().getCount();
//        System.out.println("像素的数量："+num);


        //删除geoserver图层
        geoserverRestManager.DeleteDataStores("geohazard","watervolumn");

        //计算矢量面积
        BigDecimal shp_area=waterVolumMapper.selectArea().getArea();
        System.out.println("矢量数据的面积："+shp_area);



        BigDecimal waterlevel=new BigDecimal(water_level);

        BigDecimal change=new BigDecimal(1000000000.0);
        BigDecimal r1=waterlevel.multiply(shp_area).divide(change);

        BigDecimal r2=waterVolumMapper.selectR2();
        System.out.println("第一个参数："+r1.toString());
        System.out.println("第二个参数："+r2.toString());

        BigDecimal result=r1.subtract(r2);
        System.out.println("最终估算水域体积："+result.toString());

        waterVolumMapper.OutPut();
        byte[] raster =waterVolumMapper.getResult().getTif();
        InputStream inputStream = new ByteArrayInputStream(raster);
        geoserverRestManager.uploadGeoTiff("geohazard","watervolumn",inputStream);
        inputStream.close();
        geoserverRestManager.setLayerStyle("geohazard","watervolumn","WatervolumnStyle");
        System.out.println("结束");
        return result;


    }



}
