package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.dao.pgsql.InfluencedElementsAtRiskDao;
import com.rsgisai.geohazard.level.entity.ElementsAtRisk;
import com.rsgisai.geohazard.level.exception.ElementsAtRiskStatisticException;
import com.rsgisai.geohazard.level.service.ElementsAtRiskStatisticService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.InfluencedElementsAtRisk;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @author tfh, created at 2023-04-25 10:39 PM
 */
@Service
public class ElementsAtRiskStatisticServiceImpl implements ElementsAtRiskStatisticService {
    private final InfluencedElementsAtRiskDao influencedElementsAtRiskDao;

    public ElementsAtRiskStatisticServiceImpl(InfluencedElementsAtRiskDao influencedElementsAtRiskDao) {
        this.influencedElementsAtRiskDao = influencedElementsAtRiskDao;
    }

    @Override
    public boolean iearCalculated(Long workingAreaId, Integer year) {
        return influencedElementsAtRiskDao.exist(workingAreaId, year);
    }

    @Override
    public long iearDoCalculate(Long workingAreaId, Integer year) {
        if (influencedElementsAtRiskDao.exist(workingAreaId, year)) {
            throw new ElementsAtRiskStatisticException("workingAreaId=" + workingAreaId + ", year=" + year + " already calculated.");
        }
        return influencedElementsAtRiskDao.calculate(workingAreaId, year);
    }

    @Override
    public List<ElementsAtRisk> distributionStatistic(Long workingAreaId, Integer year) {
        return influencedElementsAtRiskDao.distributionStatistic(workingAreaId, year);
    }

    @Override
    public long deleteInfluencedElementsAtRisk(Long workingAreaId, Integer year) {
        return influencedElementsAtRiskDao.delete(workingAreaId, year);
    }

    @Override
    public List<InfluencedElementsAtRisk> iearGeoJson(Long workingAreaId, Integer year) {
        return influencedElementsAtRiskDao.selectIearGeoJson(workingAreaId, year);
    }

    @Override
    public long calculateExposureIndex(Long workingAreaId, Integer year) {
        return influencedElementsAtRiskDao.calculateExposureIndex(workingAreaId, year);
    }

    @Override
    public long calculateIearClipped(String potentialId) {
        long n = influencedElementsAtRiskDao.clearIearClipped(potentialId);
        return influencedElementsAtRiskDao.calculateIearClipped(potentialId);
    }

    @Override
    public List<ElementsAtRisk> iearClippedDistribute(String potentialId) {
        long n = influencedElementsAtRiskDao.iearClippedCount(potentialId);
        if (n <= 0)
            throw new ElementsAtRiskStatisticException("no elements-at-risk in this area, or not calculated.");
        return influencedElementsAtRiskDao.iearClippedDistribute(potentialId);
    }
}
