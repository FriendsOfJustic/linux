package com.example.sys.service;


import com.example.sys.entity.WaterVolume;

import java.io.IOException;
import java.math.BigDecimal;

public interface IWaterVolumeService {


    public BigDecimal WaterVolumeAlgorithm(double water_level) throws IOException;
}
