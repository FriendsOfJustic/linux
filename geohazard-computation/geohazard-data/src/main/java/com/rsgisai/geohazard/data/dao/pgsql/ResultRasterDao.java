package com.rsgisai.geohazard.data.dao.pgsql;

import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.ResultRaster;
import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.awt.image.Raster;
import java.util.List;

@Mapper
@Repository
public interface ResultRasterDao {
    //List<ResultRaster> selectAll(ResultRaster resultRaster);

    List<ResultRaster> selectAll();


    ResultRaster selectById(Long num);

    ResultRaster selectByAlgorithm(ResultRaster resultRaster);

    RasterRecord fetchRasterTiff(ResultRaster resultRaster);

    RasterRecord fetchRasterTiffById(long resultRasterId);

    int updateLayerName(
            @Param("id") Long id,
            @Param("layerName") String layerName);

    ResultRaster selectLatest(
            @Param("workingAreaId") Long workingAreaId,
            @Param("feature") String feature);
}
