package com.rsgisai.geohazard.subsystem.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.PotentialInfluence;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-04-24 10:15 PM
 */

@Repository
@Mapper
public interface PotentialInfluenceDao {
    List<PotentialInfluence> select(PotentialInfluence potentialInfluence);


}
