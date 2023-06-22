package com.rsgisai.geohazard.level.dao.pgsql;

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
public interface AspectAlgorithmDao {
    int generate(Long workingAreaId);

    int reclassify(
            @Param("workingAreaId") long workingAreaId,
            @Param("reclassifyExpression") String reclassifyExpression,
            @Param("numberClasses") int numberClasses);

    boolean checkReclassifyUpToDate(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses);

    int updateLevelCount(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses
    );

    int updateJoinCount(
            @Param("workingAreaId") long workingAreaId,
            @Param("numberClasses") int numberClasses
    );
    /**
     * 获取Xxl实体的时候以下两个字段返回 null，原因未明，暂不影响系统功能
     * Integer joinCount;
     * Integer levelCount;
     *
     * @return 返回信息量与原来分类的对应关系List, 即 level 与 xxl 的对应关系
     */
    List<Xxl> getXxlMapping(@Param("workingAreaId") long workingAreaId, @Param("numberClasses") int numberClasses);

    /**
     * 执行信息量映射，生成信息量栅格
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
