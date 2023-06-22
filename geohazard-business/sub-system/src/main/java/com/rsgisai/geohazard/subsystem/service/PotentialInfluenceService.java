package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.system.common.entity.PotentialInfluence;

import java.util.List;

/**
 * @author tfh, created at 2023-04-24 10:19 PM
 */
public interface PotentialInfluenceService {

    //List<PotentialInfluence> select(PotentialInfluence potentialInfluence);

    List<PotentialInfluence> queryBy(PotentialInfluence potentialInfluence);
}
