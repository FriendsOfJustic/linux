package com.rsgisai.geohazard.statistic.service.impl;

import com.rsgisai.geohazard.statistic.dao.pgsql.LithologyClassificationDao;
import com.rsgisai.geohazard.statistic.entity.LithologyClassification;
import com.rsgisai.geohazard.statistic.service.LithologyClassificationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class LithologyClassificationServiceImpl implements LithologyClassificationService {
    @Autowired
    private LithologyClassificationDao lithologyClassificationDao;

    @Override
    public List<LithologyClassification> queryAll() {
        return lithologyClassificationDao.selectAll();
    }
}
