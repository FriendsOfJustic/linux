package com.rsgisai.geohazard.subsystem.dao.pgsql;


import com.rsgisai.geohazard.system.common.entity.InfluenceArea;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

import java.util.List;

/*
    created at 2023-5-17 9:11 AM
 */

@Mapper
@Repository
public interface InfluenceAreaDao {

    List<InfluenceArea> select(InfluenceArea influenceArea);

    // 根据ID删除数据
    @Delete("delete from influence_area where id = #{id}")
    public int delete(Integer id);

    // 新增数据
    //    @Options(useGeneratedKeys = true,keyProperty = "workingAreaId")
    @Insert("insert into influence_area(id, working_area_id, geom, target_region_id, area)" +
            "values(#{id},#{workingAreaId},#{geom},#{tergetRegionId},#{area})")
    public void insert(InfluenceArea influenceArea);

    // 更新数据
    @Update("update  influence_area set working_area_id = #{workingAreaId}, area = #{area} where id = #{id}")
    public void update(InfluenceArea influenceArea);

    // 根据ID查询数据
    @Select("select * from influence_area where id = #{id}")
    public InfluenceArea getById(Integer id);

    // 根据workingAreaId area查询  条件查询
    /*@Select("select * from influence_area where working_area_id = #{workingAreaId} and " +
            " area between #{areaStart} and #{areaEnd} order by area desc")
    // area是一个范围无法进行封装
    public List<InfluenceArea> list(Long workingAreaId,Double areaStart, Double areaEnd);*/

    // 根据workingAreaId area查询  条件查询
    public List<InfluenceArea> list(Long workingAreaId,Double areaStart, Double areaEnd);


    // 方案一：给字段起别名，让别名与实体类属性一致
    /*@Select("select * from influence_area where id = #{id}")
    public InfluenceArea getById(Integer id);*/
}
