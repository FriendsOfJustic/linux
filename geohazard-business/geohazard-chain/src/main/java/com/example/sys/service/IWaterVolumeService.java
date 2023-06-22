package com.example.sys.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.example.sys.entity.WaterVolume;

import java.io.IOException;
import java.math.BigDecimal;

public interface IWaterVolumeService extends IService<WaterVolume> {


    public BigDecimal WaterVolumeAlgorithm(double water_level) throws IOException;
}
