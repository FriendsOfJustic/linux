package com.rsgisai.geohazard.system.common.entity;

import lombok.Data;

import java.time.LocalDateTime;

/**
 * @author tfh, created at 2023-02-14 10:46 PM
 */
@Data
public class RasterRecord {

    private Long id;
    private Long workingAreaId;
    private LocalDateTime createTime;
    private LocalDateTime modifyTime;

    private byte[] rast;
    private byte[] tiff;
    private String numberClasses;

    public RasterRecord() {
    }

    public RasterRecord(Long id, Long workingAreaId) {
        this.id = id;
        this.workingAreaId = workingAreaId;
    }
}
