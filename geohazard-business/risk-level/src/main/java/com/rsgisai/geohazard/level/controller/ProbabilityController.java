package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.client.CompositionOperatorClient;
import com.rsgisai.geohazard.level.client.ResultRasterClient;
import com.rsgisai.geohazard.level.entity.WxxArgs;
import com.rsgisai.geohazard.level.entity.WxxResult;
import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.ResultRaster;
import org.springframework.web.bind.annotation.*;

/**
 * @author tfh, created at 2023-04-05 7:34 PM
 * 危险性评价接口
 */

@RestController
@RequestMapping({
        "/wxx",
        "geohazard-probability",
        "probability"
})
public class ProbabilityController {
    private static final String GH_PROBABILITY_GHDSL_NAME = "GH_Probability";
    private static final String GH_PROBABILITY_EARTHQUAKE_GHDSL_NAME = "GH_ProbabilityEarthquake";
    private final CompositionOperatorClient compositionOperatorClient;
    private final ResultRasterClient resultRasterClient;

    public ProbabilityController(CompositionOperatorClient compositionOperatorClient, ResultRasterClient resultRasterClient) {
        this.compositionOperatorClient = compositionOperatorClient;
        this.resultRasterClient = resultRasterClient;
    }

    @PostMapping({
            "/wxxevaluation",
            "/evaluation",
    })
    public R<WxxResult> eval(WxxArgs wxxArgs) {
        System.out.println("wxxArgs = " + wxxArgs);

        WxxResult wxxResult = new WxxResult();
        wxxResult.resultLayerName = "geohazard_probability_" + wxxArgs.workingAreaId;

        return R.ok(wxxResult);
    }

    @GetMapping({
            "/layer-name",
            "/layerName"
    })
    public R<String> layerName(Long workingAreaId) {
        return R.ok("geohazard_probability_" + workingAreaId);
    }

    @PostMapping("/earthquake")
    public R<GeohazardComputationJob> earthquake(@RequestBody CompositionOperator compositionOperator) {
        if (compositionOperator.arguments == null) {
            throw new SusceptibilityAlgorithmException("please provide susceptibility arguments");
        }
        if (!(compositionOperator.arguments.containsKey("earthquakeWeight") &&
                compositionOperator.arguments.containsKey("susceptibilityWeight")
        )) {
            throw new SusceptibilityAlgorithmException("please provide " +
                    "susceptibilityWeight, " +
                    "earthquakeWeight, "
            );
        }
        compositionOperator.name = GH_PROBABILITY_EARTHQUAKE_GHDSL_NAME;
        return compositionOperatorClient.submit(compositionOperator);
    }
    @GetMapping("/result-layer-name")
    public R<String> resultLayerName(Long jobId) {
        R<GeohazardComputationJob> geohazardComputationJobR = compositionOperatorClient.jobStatus(jobId);
        if (geohazardComputationJobR == null) {
            throw new SusceptibilityAlgorithmException("no such job#" + jobId);
        }
        Long resultRasterId = geohazardComputationJobR.getData().resultRasterId;
        R<ResultRaster> resultRasterR = resultRasterClient.selectById(resultRasterId);
        String layerName = resultRasterR.getData().getLayerName();
        return R.ok(layerName);
    }
}
