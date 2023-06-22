package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.entity.ElementsAtRisk;
import com.rsgisai.geohazard.system.common.entity.InfluencedElementsAtRisk;

import java.util.List;

/**
 * @author tfh, created at 2023-04-25 10:39 PM
 */
public interface ElementsAtRiskStatisticService {
    /**
     * query if influenced-elements-at-risk(iear) has been calculated
     */
    boolean iearCalculated(Long workingAreaId, Integer year);

    long iearDoCalculate(Long workingAreaId, Integer year);

    List<ElementsAtRisk> distributionStatistic(Long workingAreaId, Integer year);

    long deleteInfluencedElementsAtRisk(Long workingAreaId, Integer year);

    List<InfluencedElementsAtRisk> iearGeoJson(Long workingAreaId, Integer year);

    long calculateExposureIndex(Long workingAreaId, Integer year);

    long calculateIearClipped(String potentialId);

    List<ElementsAtRisk> iearClippedDistribute(String potentialId);
}
