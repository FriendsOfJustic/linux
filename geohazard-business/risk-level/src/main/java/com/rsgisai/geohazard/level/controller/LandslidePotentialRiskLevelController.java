package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.entity.RiskLevel;
import com.rsgisai.geohazard.level.service.LandslidePotentialRiskLevelService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author tfh, created at 2023-06-07 10:33 PM
 */
@RestController
@RequestMapping("landslide-potential-risk-level")
public class LandslidePotentialRiskLevelController {
    @Autowired
    LandslidePotentialRiskLevelService landslidePotentialRiskLevelService;

    @PostMapping("/evaluate")
    public R<?> evaluate(
            String no
    ) {
        RiskLevel riskLevel = landslidePotentialRiskLevelService.evaluate(no);
        return R.ok(riskLevel);
    }


}
