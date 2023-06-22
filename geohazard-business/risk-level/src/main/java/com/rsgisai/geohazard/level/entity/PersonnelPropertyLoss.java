package com.rsgisai.geohazard.level.entity;

import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @author tfh, created at 2023-06-07 8:06 PM
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class PersonnelPropertyLoss {
    String no;
    Long personnelLoss;

    Double propertyLoss;

    String hazardLevel;
}
