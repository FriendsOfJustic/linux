package com.rsgisai.geohazard.level.dao.pgsql;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.entity.RasterDaoParam;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-02-16 5:03 PM
 */
@Mapper
@Repository
public interface RasterDao {

    RasterRecord fetchRaster(RasterDaoParam rasterDaoParam);
    RasterRecord fetchOriginRaster(RasterQueryVo rasterQueryVo);
    RasterRecord fetchResultRaster(RasterQueryVo rasterQueryVo);

    RasterRecord fetchEvaluationRaster(RasterQueryVo rasterQueryVo);
    RasterRecord fetchXxlAllRaster(RasterQueryVo rasterQueryVo);

    List<RasterRecord> select(RasterDaoParam rasterDaoParam);
    List<RasterRecord> selectNumClasses(RasterDaoParam rasterDaoParam);

    List<RasterRecord> selectEvaluation(RasterDaoParam rasterDaoParam);

    int uploadRaster(RasterRecord rasterRecord);


}
