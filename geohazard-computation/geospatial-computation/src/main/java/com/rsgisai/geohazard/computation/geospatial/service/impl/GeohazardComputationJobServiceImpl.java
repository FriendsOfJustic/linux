package com.rsgisai.geohazard.computation.geospatial.service.impl;

import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.GeohazardComputationJobDao;
import com.rsgisai.geohazard.computation.geospatial.service.GeohazardComputationJobService;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @author tfh, created at 2023-04-06 10:38 AM
 */
@Service
public class GeohazardComputationJobServiceImpl implements GeohazardComputationJobService {
    @Autowired
    private GeohazardComputationJobDao geohazardComputationJobDao;

    @Override
    public GeohazardComputationJob query(Long jobId) {
        return geohazardComputationJobDao.selectById(jobId);
    }

    @Override
    public int add(GeohazardComputationJob geohazardComputationJob) {
        return geohazardComputationJobDao.insert(geohazardComputationJob);
    }
}
