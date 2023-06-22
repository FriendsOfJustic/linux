package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.level.entity.LandslidePotential;
import com.rsgisai.geohazard.level.entity.RiskLevel;
import com.rsgisai.geohazard.level.service.LandslideActivityService;
import org.apache.ibatis.annotations.MapKey;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Map;

/**
 * @author tfh, created at 2023-06-07 9:48 PM
 */
@Mapper
@Repository
public interface LandslidePotentialDao {
    List<LandslidePotential> selectAll();

    // 没问题，不要担心这个爆红说需要添加@MapKey
    Map<String, Object> selectParam(
            @Param("no") String no);

    int updateActivity(
            @Param("no") String no,
            @Param("activityLevel") String activityLevel);

    LandslidePotential selectByNo(
            @Param("no") String no);

    int updateRiskLevel(RiskLevel level);
}
