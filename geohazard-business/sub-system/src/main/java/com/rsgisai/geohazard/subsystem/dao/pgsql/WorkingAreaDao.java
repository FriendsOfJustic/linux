package com.rsgisai.geohazard.subsystem.dao.pgsql;

import com.rsgisai.geohazard.entity.WorkingArea;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface WorkingAreaDao {
    Integer insert(WorkingArea workingArea);

    Integer update(WorkingArea workingArea);

    List<WorkingArea> select();
}
