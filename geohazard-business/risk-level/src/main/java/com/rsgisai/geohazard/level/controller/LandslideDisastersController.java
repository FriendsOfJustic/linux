package com.rsgisai.geohazard.level.controller;


import com.rsgisai.geohazard.level.service.LandslideDisastersService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.GeohazardRisk;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 *  @author yyh, created at 2023-05-27 10:37 AM
 */
@RestController
@RequestMapping("/landslide_disasters")
public class LandslideDisastersController {

    @Autowired
    private LandslideDisastersService landslideDisastersService;

    // 通过危险性和易损性的组合得到风险等级，将其插入geohazard_risk表中
    @GetMapping("/insertRisk")
    public R<String> insertRisk(GeohazardRisk geohazardRisk){
        landslideDisastersService.insertRisk(geohazardRisk);
        return R.success("OK");
    }

    // 区域风险等级评价
    @GetMapping("/selectRast")
    public R<List<GeohazardRisk>> selectRast(GeohazardRisk geohazardRisk){
        return R.ok(landslideDisastersService.selectRast(geohazardRisk));
    }
}
