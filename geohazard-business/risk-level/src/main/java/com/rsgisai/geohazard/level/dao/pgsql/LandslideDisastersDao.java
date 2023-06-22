package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.GeohazardRisk;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 *  @author yyh, created at 2023-05-27 10:37 AM
 */

@Mapper
@Repository
public interface LandslideDisastersDao {
    // 通过危险性和易损性的组合得到风险等级，将其插入geohazard_risk表中
    List<GeohazardRisk> insertRisk(GeohazardRisk geohazardRisk);

    // 区域风险等级评价
    List<GeohazardRisk> selectRast(GeohazardRisk geohazardRisk);

    // 单体风险等级评价
    List<GeohazardRisk> selectValues1(GeohazardRisk geohazardRisk);

}
