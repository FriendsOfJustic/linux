package com.rsgisai.geohazard.level.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-02-14 10:46 PM
 */
@Data
public class RasterStats {

    private Long count;
    private Double sum;
    private Double mean;
    private Double stddev;
    private Double min;
    private Double max;

}
