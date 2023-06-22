package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.LinearModel;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

/**
 * @author tfh, created at 2023-05-25 3:28 PM
 */
@Mapper
@Repository
public interface LandslideActivityModelDao {
    Long insert(LinearModel model);

    LinearModel selectLast();
}
