package com.rsgisai.geohazard.level.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-04-05 7:40 PM
 */
@Data
public class WxxArgs {
    public Long workingAreaId;
    /*
     * 易发性权重
     */
    Double yfxqz;

    /**
     * 降雨量权重
     */
    Double jylqz;
}
