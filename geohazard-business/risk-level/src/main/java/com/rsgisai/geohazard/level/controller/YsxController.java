package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.entity.YfxArgs;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author tfh, created at 2023-04-05 7:34 PM
 * 危险性评价接口
 */

@RestController
@RequestMapping({
        "/ysx",
})
public class YsxController {
    @PostMapping({
            "/yfxevaluation",
            "/evaluation",
    })
    public R<?> eval(YfxArgs wxxArgs) {
        throw new RuntimeException("to be implemented.");
//        return R.ok(wxxResult);// todo
    }

    @GetMapping({
            "/layer-name",
            "/layerName"
    })
    public R<String> layerName(Long workingAreaId) {
        return R.ok("vulnerability_" + workingAreaId);
    }
}
