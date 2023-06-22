package com.rsgisai.geohazard.system.common.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-04-24 10:12 PM
 */
@Data
public class PotentialInfluence {
    private String id;
    private Long workingAreaId;
    //private Long working_area_id;
    private Integer year;
    /**
     * WKB geometry
     */
    private byte[] geom;

    private String geoJson;
    private String category;
}
