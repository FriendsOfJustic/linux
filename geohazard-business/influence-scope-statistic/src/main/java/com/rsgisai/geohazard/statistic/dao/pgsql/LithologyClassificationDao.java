package com.rsgisai.geohazard.statistic.dao.pgsql;

import com.rsgisai.geohazard.statistic.entity.LithologyClassification;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface LithologyClassificationDao {
    List<LithologyClassification> selectAll();
}
