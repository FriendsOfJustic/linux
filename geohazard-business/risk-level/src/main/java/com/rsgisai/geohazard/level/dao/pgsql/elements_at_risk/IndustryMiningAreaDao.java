package com.rsgisai.geohazard.level.dao.pgsql.elements_at_risk;

import com.rsgisai.geohazard.level.entity.elements_at_risk.ForestArea;
import com.rsgisai.geohazard.level.entity.elements_at_risk.IndustryMiningArea;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-05-26 4:41 PM
 */

@Mapper
@Repository
public interface IndustryMiningAreaDao {

    List<IndustryMiningArea> select(
            @Param("workingAreaId") Long workingAreaId,
            @Param("year") Integer year,
            @Param("potentialId") String potentialId
    );
}