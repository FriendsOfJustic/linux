package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.entity.EvaluationRasterRecord;
import com.rsgisai.geohazard.level.entity.RasterStats;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-02-14 10:40 AM
 */
@Mapper
@Repository
public interface EvaluationAlgorithmDao {

    void calculateTotalInformationAmount(
            @Param("workingAreaId") long workingAreaId,
            @Param("demNumberClasses") int demNumberClasses,
            @Param("slopeNumberClasses") int slopeNumberClasses,
            @Param("aspectNumberClasses") int aspectNumberClasses,
            @Param("curvatureNumberClasses") int curvatureNumberClasses
    );

    void calculateEvaluationReclassify(
            @Param("workingAreaId") long workingAreaId,
            @Param("demNumberClasses") int demNumberClasses,
            @Param("slopeNumberClasses") int slopeNumberClasses,
            @Param("aspectNumberClasses") int aspectNumberClasses,
            @Param("curvatureNumberClasses") int curvatureNumberClasses,
            @Param("outNumberClasses") int outNumberClasses,
            @Param("reclassifyExpression") String reclassifyExpression
    );

    RasterStats getStats(
            @Param("workingAreaId") long workingAreaId,
            @Param("demNumberClasses") int demNumberClasses,
            @Param("slopeNumberClasses") int slopeNumberClasses,
            @Param("aspectNumberClasses") int aspectNumberClasses,
            @Param("curvatureNumberClasses") int curvatureNumberClasses,
            @Param("outNumberClasses") int outNumberClasses
    );

    List<EvaluationRasterRecord> select(EvaluationRasterRecord evaluationRasterRecord);

    RasterRecord fetchRaster(RasterQueryVo rasterQueryVo);
}
