package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.computation.geospatial.entity.InformationAmount;
import com.rsgisai.geohazard.computation.geospatial.entity.RasterQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface InformationAmountDao {
    /**
     * required param
     * 1. workingAreaId
     * 2. userId
     * 3. numberClasses
     * 4. feature
     * 5. inputRasterId
     * 6. inputPointsId
     *
     * @return number of rows affected
     */
    int calculateJoinCount(RasterQuery rasterQuery);

    int clearJoinCount(RasterQuery rasterQuery);

    int calculateLevelCount(RasterQuery rasterQuery);

    int clearLevelCount(RasterQuery rasterQuery);


    List<InformationAmount> getInformationAmountMapping(RasterQuery rasterQuery);

    int populateInformationAmount(RasterQuery rasterQuery);
}
