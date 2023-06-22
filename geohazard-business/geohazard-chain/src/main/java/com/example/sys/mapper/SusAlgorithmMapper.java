package com.example.sys.mapper;


import com.example.sys.entity.ResultTif;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.postgresql.util.PSQLException;
import org.springframework.stereotype.Repository;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.List;

@Repository
@Mapper
public interface SusAlgorithmMapper {


    //chain_sus_dem
    //向chain_sus_reclass插入重分类的栅格
    void insertReclass(@Param("exp")String exp,@Param("num")Integer num);


    //将选定id的tif按照exp重分类
    void insertRedefine(@Param("exp")String exp,@Param("num")Integer id) throws PSQLException;

    //删除 myrast、chain_sus_reclass两个表
    void deleteAll();


    //查询指定第num个分类结果tif的 像素值=val 的数量
    Integer selectClass(@Param("num")Integer num,@Param("val")Integer val);

    //向myrast中插入数据
    void insertMidResult();


    //查找chain_sus_reclass中栅格数量
    Integer selectReclassCount();


    //查找栅格的最大值
    Double selectMax(@Param("num")Integer id);


    //查找栅格的最小值
    Double selectMin(@Param("num")Integer id);

    //查找myrast中栅格数量
    int selectMidResultCount();


//    //查询灾害点的所有横坐标
//    List<Double> selectRiskPoint_x();
//
//    //查询所有灾害点的纵坐标
//    List<Double>  selectRiskPoint_y();


    //查询灾害点的总数量
    Integer selectRiskPointCount();


    //返回编号为id=num的tif的所有波段的像原的数量——倒序排列
    List<Integer> selectTifEachBandCount(@Param("num")Integer num);

    List<Integer> selectRiskPointCountPerClass(@Param("id") Integer id);
    //叠加七个tif得到结果
    void selectResultTif();

    List<Integer> selectTifEachBandValue(@Param("num")Integer num);
    //返回编号为id=num的tif的所有像原的总数量
    Integer selectAllCount(@Param("num")Integer num);



    //发布图层
    ResultTif selectResultImage(@Param("id")Integer id);
}
