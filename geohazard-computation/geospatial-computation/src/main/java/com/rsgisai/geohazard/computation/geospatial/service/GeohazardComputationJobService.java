package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.system.common.GeohazardComputationJob;

/**
 * @author tfh, created at 2023-04-06 10:38 AM
 */
public interface GeohazardComputationJobService {
    public GeohazardComputationJob query(Long jobId);

    int add(GeohazardComputationJob geohazardComputationJob);
}
