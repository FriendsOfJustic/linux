package com.rsgisai.geohazard.computation.geospatial.dao.mysql;


import com.rsgisai.geohazard.computation.geospatial.entity.Landslide;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;


@Mapper
@Repository
public interface LandslideDao {
    List<Landslide> list();

    Landslide selectById(Integer id);
}
