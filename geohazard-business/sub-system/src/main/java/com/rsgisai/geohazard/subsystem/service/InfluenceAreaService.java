package com.rsgisai.geohazard.subsystem.service;


import com.rsgisai.geohazard.system.common.entity.InfluenceArea;
//import org.springframework.stereotype.Service;

import java.util.List;

/*
     created at 2023-05-17 9:04 AM
 */

public interface InfluenceAreaService {

    List<InfluenceArea> queryById(Integer id);

    List<InfluenceArea> select(Long workingAreaId,Double areaStart, Double areaEnd);
}
