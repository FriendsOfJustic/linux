package com.rsgisai.geohazard.subsystem.controller;


/*
     created at 2023-05-17 9:04 AM
 */

import com.rsgisai.geohazard.subsystem.service.InfluenceAreaService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.InfluenceArea;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/influnce-area")
public class InfluenceAreaController {

    @Autowired
    InfluenceAreaService influenceAreaService;


    @GetMapping
    public R<List<InfluenceArea>> select(@RequestParam("workingAreaId") Long workingAreaId,
                                         @RequestParam("areaStart") Double areaStart,
                                         @RequestParam("areaEnd") Double areaEnd){

        return R.ok(influenceAreaService.select(workingAreaId,areaStart,areaEnd));
    }
}
