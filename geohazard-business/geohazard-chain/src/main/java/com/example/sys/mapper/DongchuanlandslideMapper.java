package com.example.sys.mapper;

import com.example.sys.entity.Dongchuanlandslide;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.example.sys.entity.ResultTif;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author sht
 * @since 2023-04-17
 */

@Mapper
public interface DongchuanlandslideMapper extends BaseMapper<Dongchuanlandslide> {
    Dongchuanlandslide selectBynumber(@Param("number")String number);


    void PrepareWork();

    void LoopAssignment(@Param("table") String t1,@Param("curname") String t2,@Param("prevname") String t3,@Param("id") String id,@Param("value") Integer value);

    void InsertResult(@Param("tablename") String t1);


    void DeleteResult();

    ResultTif selectResultImage(@Param("name")String name);

    void deleteLoop(@Param("name") String name);

    void CreateResultLayerData();

    void InsertResultGeom(@Param("id") String id ,@Param("risklevel") Integer risklevel);
}
