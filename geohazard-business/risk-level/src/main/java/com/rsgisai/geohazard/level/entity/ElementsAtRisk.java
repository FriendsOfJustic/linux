package com.rsgisai.geohazard.level.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-02-09 4:02 PM
 */
@Data
public class ElementsAtRisk {

    Long id;
    Long gridcode;
    String className;
    Double area;
    Long workingAreaId;
    String type;
    Integer year;
    String name;
    String geom;
    Boolean isAtRisk;
}
