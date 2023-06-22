package com.rsgisai.geohazard.system.common.entity;

import lombok.Data;

import java.util.LinkedHashMap;
import java.util.Map;

/**
 * @author tfh, created at 2023-05-24 11:36 PM
 */
@Data
public class LinearModel {
    public Long id;


    Map<String, Double> weight = new LinkedHashMap<>();
    Double bias;


    Double prediction;
    public String serializedObject;
}
