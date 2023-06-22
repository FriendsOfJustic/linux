package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.entity.RiskLevel;

/**
 * @author tfh, created at 2023-06-07 10:40 PM
 */
public interface LandslidePotentialRiskLevelService {
    RiskLevel evaluate(String no);

}
