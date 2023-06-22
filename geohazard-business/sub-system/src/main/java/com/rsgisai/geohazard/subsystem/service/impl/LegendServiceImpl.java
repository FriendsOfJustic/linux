package com.rsgisai.geohazard.subsystem.service.impl;

import com.rsgisai.geohazard.subsystem.dao.pgsql.LegendDao;
import com.rsgisai.geohazard.subsystem.service.LegendService;
import com.rsgisai.geohazard.system.common.entity.Legend;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @author temTe
 * @description 针对表【legend】的数据库操作Service实现
 * @createDate 2023-05-05 10:21:59
 */
@Service
public class LegendServiceImpl implements LegendService {

    @Autowired
    LegendDao legendDao;

    @Override
    public List<Legend> queryByName(String name) {
        Legend legend = new Legend();
        legend.setName(name);
        return legendDao.select(legend);
    }

    @Override
    public int insert(List<Legend> legendList) {
        int count = 0;
        for (Legend legend : legendList) {
            count += legendDao.insert(legend);
        }
        return count;
    }
}




