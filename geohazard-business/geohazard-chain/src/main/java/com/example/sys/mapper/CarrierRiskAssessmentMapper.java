package com.example.sys.mapper;


import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface CarrierRiskAssessmentMapper {


    List<Integer> selectFloodAreaId();
    void CreateMidResult(@Param("id") Integer _id);

    List<Double> MidResultArea();

    List<Integer> MidResultType();

    void CreateResultLayer();


    void InsertResultLayer(@Param("id")Integer id ,@Param("level") Integer risklevel);




}
