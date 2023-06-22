package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.dao.pgsql.LandslideDisastersDao;
import com.rsgisai.geohazard.level.service.LandslideDisastersService;
import com.rsgisai.geohazard.system.common.entity.GeohazardRisk;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 *  @author yyh, created at 2023-05-27 10:37 AM
 */

@Service
public class LandslideDisastersServiceImpl implements LandslideDisastersService {
    @Autowired
    LandslideDisastersDao landslideDisastersDao;

    // 通过危险性和易损性的组合得到风险等级，将其插入geohazard_risk表中
    @Override
    public List<GeohazardRisk> insertRisk(GeohazardRisk geohazardRisk) {
        return landslideDisastersDao.insertRisk(geohazardRisk);
    }

    // 区域风险等级评价
    @Override
    public List<GeohazardRisk> selectRast(GeohazardRisk geohazardRisk){
        return landslideDisastersDao.selectRast(geohazardRisk);
    }
}
