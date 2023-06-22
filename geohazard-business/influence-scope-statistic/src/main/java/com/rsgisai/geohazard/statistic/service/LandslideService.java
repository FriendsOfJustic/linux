package com.rsgisai.geohazard.statistic.service;

import com.rsgisai.geohazard.entity.Correlation;
import com.rsgisai.geohazard.entity.Landslide;

import java.util.List;

public interface LandslideService {
    List<Landslide> list();

    Landslide selectById(Integer id);

    Correlation correlation();
}
