package com.rsgisai.geohazard.subsystem.service.impl;


import com.rsgisai.geohazard.subsystem.dao.pgsql.InfluenceAreaDao;
import com.rsgisai.geohazard.subsystem.service.InfluenceAreaService;
import com.rsgisai.geohazard.system.common.entity.InfluenceArea;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/*
     created at 2023-05-17 9:04 AM
     针对表【InflunceArea】的数据库操作Service实现
 */
@Service
public class InfluenceAreaServiceImpl implements InfluenceAreaService {
    @Autowired
    InfluenceAreaDao influnceAreaDao;

    @Override
    public List<InfluenceArea> queryById(Integer id){
        InfluenceArea influenceArea = new InfluenceArea();
        influenceArea.setId(id);
        return influnceAreaDao.select(influenceArea);
    }

    @Override
    public List<InfluenceArea> select(Long workingAreaId,Double areaStart, Double areaEnd){
        return influnceAreaDao.list(workingAreaId,areaStart,areaEnd);
    }
}
