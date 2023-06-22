package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.entity.PersonnelPropertyLoss;

/**
 * @author tfh, created at 2023-06-07 5:03 PM
 */
public interface PersonnelPropertyLossService {

    PersonnelPropertyLoss calculateLoss(String no);
}
