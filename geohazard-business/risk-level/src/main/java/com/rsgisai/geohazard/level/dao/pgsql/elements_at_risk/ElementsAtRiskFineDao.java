package com.rsgisai.geohazard.level.dao.pgsql.elements_at_risk;

import com.rsgisai.geohazard.level.entity.PersonnelPropertyLoss;
import com.rsgisai.geohazard.level.entity.elements_at_risk.ElementsAtRiskFine;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-05-26 4:41 PM
 */

@Mapper
@Repository
public interface ElementsAtRiskFineDao {
    List<ElementsAtRiskFine> selectAll();
    List<ElementsAtRiskFine> selectByLandslidePotentialInfluence(
            @Param("potentialInfluenceNo") String potentialInfluenceNo);

    int updatePersonnelPropertyLoss(PersonnelPropertyLoss personnelPropertyLoss);
}
