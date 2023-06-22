package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.system.common.entity.Legend;

import java.util.List;

/**
 * @author Richard
 */
public interface LegendService {

    List<Legend> queryByName(String name);

    int insert(List<Legend> legendList);
}
