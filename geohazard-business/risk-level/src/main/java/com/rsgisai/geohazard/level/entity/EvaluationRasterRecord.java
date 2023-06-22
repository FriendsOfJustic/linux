package com.rsgisai.geohazard.level.entity;

import lombok.Data;

import java.time.LocalDateTime;

/**
 * @author tfh, created at 2023-02-18 2:27 PM
 */
@Data
public class EvaluationRasterRecord {
    public Long id;
    public Long workingAreaId;
    public Integer demNumberClasses;
    public Integer slopeNumberClasses;
    public Integer aspectNumberClasses;
    public Integer curvatureNumberClasses;
    public Integer outNumberClasses;
    public LocalDateTime createTime;
    public LocalDateTime modifyTime;
}
