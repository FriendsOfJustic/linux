package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.entity.YfxArgs;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.*;

/**
 * @author tfh, created at 2023-04-05 7:34 PM
 * 危险性评价接口
 */

@RestController
@RequestMapping({
        "/fbtj",
})
public class FbtjController {

    @GetMapping({
            "/yssjLayerName"
    })
    public R<String> layerName(@RequestParam(value = "workingAreaId", required = false) Long workingAreaId) {
        return R.ok("elements_at_risk");
    }
}
