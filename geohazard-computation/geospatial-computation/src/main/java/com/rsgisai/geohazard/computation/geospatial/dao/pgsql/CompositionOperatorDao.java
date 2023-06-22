package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

@Mapper
@Repository
public interface CompositionOperatorDao {
    boolean exist(CompositionOperator compositionOperator);

    void insert(CompositionOperator compositionOperator);

    int update(CompositionOperator compositionOperator);

    CompositionOperator selectOne(CompositionOperator compositionOperator);
    CompositionOperator selectByName(String name);
}
