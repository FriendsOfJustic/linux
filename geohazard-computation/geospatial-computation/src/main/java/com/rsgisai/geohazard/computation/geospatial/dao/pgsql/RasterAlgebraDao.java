package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.InformationAmount;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface RasterAlgebraDao {

    int rasterSum(RasterQuery rasterQuery);
    int mapAlgebraDouble(RasterQuery rasterQuery);

}
