package com.rsgisai.geohazard.statistic.service.impl;

import com.rsgisai.geohazard.statistic.dao.pgsql.LandslideHazardDao;
import com.rsgisai.geohazard.statistic.entity.LandslideHazard;
import com.rsgisai.geohazard.statistic.service.LandslideHazardService;
import com.rsgisai.geohazard.statistic.service.LandslideService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class LandslideHazardServiceImpl implements LandslideHazardService {
    @Resource
    private LandslideHazardDao landslideHazardDao;

    @Override
    public List<LandslideHazard> queryAll() {
        return landslideHazardDao.selectAll();
    }
}
