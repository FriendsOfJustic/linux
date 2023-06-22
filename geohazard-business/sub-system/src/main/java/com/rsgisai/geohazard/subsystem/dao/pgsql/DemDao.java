package com.rsgisai.geohazard.subsystem.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

/**
 * @author tfh, created at 2023-02-17 10:01 AM
 */
@Mapper
@Repository
public interface DemDao {

    RasterRecord select(RasterRecord rasterRecord);
}
