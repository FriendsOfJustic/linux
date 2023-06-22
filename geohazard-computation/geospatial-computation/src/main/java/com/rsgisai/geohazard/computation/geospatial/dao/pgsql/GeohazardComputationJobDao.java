package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

/**
 * @author tfh, created at 2023-04-06 10:39 AM
 */
@Mapper
@Repository
public interface GeohazardComputationJobDao {
    GeohazardComputationJob selectById(Long jobId);

    int insert(GeohazardComputationJob geohazardComputationJob);

    int updateCurrentLine(
            @Param("jobId") Long jobId,
            @Param("currentLine") int currentLine);

    int updateSavedResult(
           @Param("jobId") long jobId,
           @Param("savedRasterId") long savedRasterId);
}
