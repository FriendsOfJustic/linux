package com.rsgisai.geohazard.subsystem.controller;

import com.rsgisai.geohazard.subsystem.service.LegendService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.Legend;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @author tfh, created at 2023-05-05 10:14 AM
 */
@RestController
@RequestMapping("/legend")
public class LegendController {
    @Autowired
    LegendService legendService;
    @GetMapping
    public R<List<Legend>> list(@RequestParam("name") String name) {

        return R.ok(legendService.queryByName(name));
    }


}
