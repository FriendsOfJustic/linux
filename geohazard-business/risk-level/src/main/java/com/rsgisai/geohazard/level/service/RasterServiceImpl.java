package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.level.dao.pgsql.RasterDao;
import com.rsgisai.geohazard.level.entity.RasterDaoParam;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @author tfh, created at 2023-02-16 5:01 PM
 */
@Service
public class RasterServiceImpl implements RasterService {
    @Autowired
    private RasterDao rasterDao;

    @Override
    public byte[] getRasterInputStream(RasterQueryVo rasterQueryVo) {
        RasterDaoParam rasterDaoParam = new RasterDaoParam(rasterQueryVo);
        RasterRecord rasterRecord = rasterDao.fetchRaster(rasterDaoParam);
        return rasterRecord.getRast();
    }

    @Override
    public byte[] getEvaluationInputStream(RasterQueryVo rasterQueryVo) {
        RasterRecord rasterRecord = rasterDao.fetchEvaluationRaster(rasterQueryVo);
        return rasterRecord.getRast();
    }

    @Override
    public byte[] getXxlAllInputStream(RasterQueryVo rasterQueryVo) {
        RasterRecord rasterRecord = rasterDao.fetchXxlAllRaster(rasterQueryVo);
        return rasterRecord.getRast();
    }
}
