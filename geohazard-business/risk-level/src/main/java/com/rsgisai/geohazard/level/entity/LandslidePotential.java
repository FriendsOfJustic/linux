package com.rsgisai.geohazard.level.entity;

import lombok.Data;

/**
 * @author tfh, created at 2023-06-07 10:24 PM
 */
@Data
public class LandslidePotential {
    String no;
    String longitude;
    String latitude;
    String hazardLevel;
    String activityLevel;
    Double activityValue;

}
