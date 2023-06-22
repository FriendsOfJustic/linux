package com.rsgisai.geohazard.system.common;

import lombok.Data;

import java.time.LocalDateTime;
import java.util.*;

@Data
public class GeohazardComputationJob {
    public Long id;
    public Long dslId;
    public String name;

    /**
     * ready
     * executing
     */
    public String status;
    public Integer currentLine;
    public Long resultRasterId;

    public Long createBy;
    public Long modifyBy;
    public LocalDateTime createTime;
    public LocalDateTime modifyTime;
}
