package com.rsgisai.geohazard.statistic.dao.pgsql;

import com.rsgisai.geohazard.statistic.entity.LandslideHazard;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface LandslideHazardDao {
    List<LandslideHazard> selectAll();
}
