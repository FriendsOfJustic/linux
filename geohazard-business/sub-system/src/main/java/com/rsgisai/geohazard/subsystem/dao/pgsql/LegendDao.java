package com.rsgisai.geohazard.subsystem.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.Legend;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author temTe
 * @description 针对表【legend】的数据库操作Mapper
 * @createDate 2023-05-05 10:21:59
 * @Entity generator.domain.Legend
 */
@Repository
@Mapper
public interface LegendDao {

    List<Legend> select(Legend legend);

    int insert(Legend legend);
}




