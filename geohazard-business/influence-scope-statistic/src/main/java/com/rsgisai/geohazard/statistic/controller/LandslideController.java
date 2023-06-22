package com.rsgisai.geohazard.statistic.controller;

import com.rsgisai.geohazard.entity.Correlation;
import com.rsgisai.geohazard.entity.Landslide;
import com.rsgisai.geohazard.statistic.service.LandslideService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/landslide")
public class LandslideController {
    @Resource
    private LandslideService landslideService;

    @GetMapping
    public R<List<Landslide>> list() {
        return R.success(landslideService.list());
    }

    @GetMapping("/{id}")
    public R<Landslide> list(@PathVariable("id") Integer id) {
        return R.success(landslideService.selectById(id))
                .message("滑坡数据#" + id + "获取成功");
    }

    @GetMapping("/correlation")
    public R<Correlation> correlation() {
        return R.success(landslideService.correlation());
    }
}
