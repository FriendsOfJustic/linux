package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

@Mapper
@Repository
public interface SlopeDao {

    int calculate(RasterQuery rasterQuery);
}
