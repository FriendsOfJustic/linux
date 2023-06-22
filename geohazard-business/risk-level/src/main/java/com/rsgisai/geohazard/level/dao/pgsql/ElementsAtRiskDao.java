package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.level.entity.ElementsAtRisk;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface ElementsAtRiskDao {
    List<ElementsAtRisk> select(ElementsAtRisk elementsAtRisk);
}
