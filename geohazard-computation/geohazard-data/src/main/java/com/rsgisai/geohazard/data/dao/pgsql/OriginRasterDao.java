package com.rsgisai.geohazard.data.dao.pgsql;

import com.rsgisai.geohazard.data.vo.RasterQuery;
import com.rsgisai.geohazard.system.common.OriginRaster;
import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @author tfh, created at 2023-04-10 10:24 AM
 */
@Mapper
@Repository
public interface OriginRasterDao {
    List<OriginRaster> select(OriginRaster originRaster);

    RasterRecord fetchRasterTiff(OriginRaster originRaster);

    int upload(RasterQuery rasterQuery);
}
