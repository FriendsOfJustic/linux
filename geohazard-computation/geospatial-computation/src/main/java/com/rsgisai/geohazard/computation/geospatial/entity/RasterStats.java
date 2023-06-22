package com.rsgisai.geohazard.computation.geospatial.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-02-14 10:46 PM
 */
@Data
public class RasterStats {

    public Long count;
    public Double sum;
    public Double mean;
    public Double stddev;
    public Double min;
    public Double max;

}
