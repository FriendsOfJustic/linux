package com.rsgisai.geohazard.level.dao.mysql;


import com.rsgisai.geohazard.level.entity.Landslide;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;


@Mapper
@Repository
public interface LandslideDao {
    List<Landslide> list();

    Landslide selectById(Integer id);
}
