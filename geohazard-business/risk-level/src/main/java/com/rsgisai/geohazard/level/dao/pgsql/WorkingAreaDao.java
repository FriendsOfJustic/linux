package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.entity.WorkingArea;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-02-18 3:12 PM
 */
@Mapper
@Repository
public interface WorkingAreaDao {
    List<WorkingArea> select(WorkingArea workingArea);
}
