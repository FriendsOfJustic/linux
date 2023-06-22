package com.rsgisai.geohazard.statistic.controller;

import com.rsgisai.geohazard.statistic.entity.LithologyClassification;
import com.rsgisai.geohazard.statistic.service.LithologyClassificationService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("lithology-classification")
public class LithologyClassificationController {
    @Autowired
    private LithologyClassificationService lithologyClassificationService;

    @GetMapping
    public R<List<LithologyClassification>> list() {
        return R.success(lithologyClassificationService.queryAll());
    }

}
