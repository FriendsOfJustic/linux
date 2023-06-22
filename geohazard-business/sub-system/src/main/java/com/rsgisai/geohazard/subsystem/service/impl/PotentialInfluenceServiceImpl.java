package com.rsgisai.geohazard.subsystem.service.impl;

import com.rsgisai.geohazard.subsystem.dao.pgsql.PotentialInfluenceDao;
import com.rsgisai.geohazard.subsystem.service.PotentialInfluenceService;
import com.rsgisai.geohazard.system.common.entity.PotentialInfluence;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @author tfh, created at 2023-04-24 10:19 PM
 */
@Service
public class PotentialInfluenceServiceImpl implements PotentialInfluenceService {
    @Autowired
    PotentialInfluenceDao potentialInfluenceDao;

    /*@Override
    public List<PotentialInfluence> select(PotentialInfluence potentialInfluence) {
        return potentialInfluenceDao.select(potentialInfluence);
    }*/

    @Override
    public List<PotentialInfluence> queryBy(PotentialInfluence potentialInfluence) {

        return potentialInfluenceDao.select(potentialInfluence);
    }





}
