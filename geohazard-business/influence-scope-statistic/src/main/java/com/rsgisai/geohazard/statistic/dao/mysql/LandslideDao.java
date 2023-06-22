package com.rsgisai.geohazard.statistic.dao.mysql;


import com.rsgisai.geohazard.entity.Landslide;

import java.util.List;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

@Mapper
@Repository
public interface LandslideDao {
    List<Landslide> list();

    Landslide selectById(Integer id);
}
