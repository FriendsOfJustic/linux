package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.level.entity.RasterStats;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

/**
 * @author tfh, created at 2023-02-14 10:40 AM
 */
@Mapper
@Repository
public interface AlgorithmDao {
    RasterStats getStats(Long workingAreaId, Integer numberClasses);
}
