package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.level.entity.ElementsAtRisk;
import com.rsgisai.geohazard.system.common.entity.InfluencedElementsAtRisk;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-04-25 10:43 PM
 */
@Mapper
@Repository
public interface InfluencedElementsAtRiskDao {

    boolean exist(
            @Param("workingAreaId") Long workingAreaId,
            @Param("year") Integer year);

    long calculate(
            @Param("workingAreaId") Long workingAreaId,
            @Param("year") Integer year);

    long calculateExposureIndex(
            @Param("workingAreaId") Long workingAreaId,
            @Param("year") Integer year);

    List<ElementsAtRisk> distributionStatistic(
            @Param("workingAreaId") Long workingAreaId,
            @Param("year") Integer year);

    long delete(Long workingAreaId, Integer year);

    List<InfluencedElementsAtRisk> selectIearGeoJson(
            @Param("workingAreaId") Long workingAreaId,
            @Param("year") Integer year);

    long calculateIearClipped(
            @Param("potentialId") String potentialId);

    long clearIearClipped(
            @Param("potentialId") String potentialId);

    long iearClippedCount(
            @Param("potentialId") String potentialId);

    List<ElementsAtRisk> iearClippedDistribute(
            @Param("potentialId") String potentialId);
}
