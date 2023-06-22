package com.rsgisai.geohazard.system.common.entity;

import java.io.Serializable;

import lombok.Data;

/**
 * @TableName legend
 */
@Data
public class Legend implements Serializable {
    /**
     *
     */
    private Long id;

    /**
     * name of the legend
     */
    private String name;

    /**
     * corresponding value
     */
    private String value;

    /**
     * corresponding label
     */
    private String label;

    /**
     * corresponding color ( example #112233 )
     */
    private String rgb;

    /**
     * categorized / graduated
     */
    private String type;

    private static final long serialVersionUID = -2181747685352286392L;
}