package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.entity.RasterStats;
import com.rsgisai.geohazard.level.entity.Xxl;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-02-14 10:40 AM
 */
@Mapper
@Repository
public interface SlopeAlgorithmDao {
    int generate(Long workingAreaId);


    int reclassify(
            @Param("workingAreaId") long workingAreaId,
            @Param("reclassifyExpression") String reclassifyExpression,
            @Param("numberClasses") int numberClasses);

    /**
     * @return True if up to date
     */
    Boolean checkUpToDate(Long workingAreaId);

    int checkGenerated(Long workingAreaId);

    RasterStats getStats(RasterRecord rasterRecord);

    int updateLevelCount(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses
    );

    int updateJoinCount(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses
    );

    List<Xxl> getXxlMapping(@Param("workingAreaId") long workingAreaId, @Param("numberClasses") int numberClasses);

    /**
     * 执行信息量映射，生成信息量栅格
     *
     * @param workingAreaId
     * @param numberClasses
     * @param xxlMappingExpression
     * @return
     */
    int xxlMapping(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses,
            @Param("xxlMappingExpression") String xxlMappingExpression);

    boolean xxlExist(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses);

    boolean reclassifyExist(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses
    );
}
