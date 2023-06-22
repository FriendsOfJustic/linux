package com.rsgisai.geohazard.statistic.controller;

import com.rsgisai.geohazard.statistic.entity.LandslideHazard;
import com.rsgisai.geohazard.statistic.service.LandslideHazardService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/landslide-hazard")
public class LandslideHazardController {
    @Resource
    private LandslideHazardService landslideHazardService;

    @GetMapping
    public R<List<LandslideHazard>> list() {
        List<LandslideHazard> landslideHazardList = landslideHazardService.queryAll();
        return R.success(landslideHazardList);
    }
}
