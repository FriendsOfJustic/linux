package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.client.CompositionOperatorClient;
import com.rsgisai.geohazard.level.client.ResultRasterClient;
import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.ResultRaster;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * @author tfh, created at 2023-04-07 3:34 PM
 */
@RestController
@RequestMapping({
        "/yfx",
        "/susceptibility"
})
public class SusceptibilityController {
    private final String GH_SUSCEPTIBILITY_GHDSL_NAME = "GH_Susceptibility";
    private final String SUSCEPTIBILITY_FEATURE_NAME = "susceptibility";
    @Autowired
    CompositionOperatorClient compositionOperatorClient;
    @Autowired
    private ResultRasterClient resultRasterClient;

    @GetMapping("/operator")
    public R<CompositionOperator> getGhdsl() {
        return compositionOperatorClient.getGhdsl(GH_SUSCEPTIBILITY_GHDSL_NAME);
    }

    @PutMapping("/operator")
    public R<CompositionOperator> updateGhdsl(CompositionOperator compositionOperator) {
        compositionOperator.name = GH_SUSCEPTIBILITY_GHDSL_NAME;
        return compositionOperatorClient.update(compositionOperator);
    }

    @PostMapping("/operator")
    public R<GeohazardComputationJob> operate(@RequestBody CompositionOperator compositionOperator) {
        if (compositionOperator.arguments == null) {
            throw new SusceptibilityAlgorithmException("please provide susceptibility arguments");
        }
        if (!(compositionOperator.arguments.containsKey("demNumberClasses") &&
                compositionOperator.arguments.containsKey("slopeNumberClasses") &&
                compositionOperator.arguments.containsKey("engineeringGeologicalRockGroupNumberClasses") &&
                compositionOperator.arguments.containsKey("faultStructureNumberClasses") &&
                compositionOperator.arguments.containsKey("aspectNumberClasses"))) {
            throw new SusceptibilityAlgorithmException("please provide demNumberClasses, " +
                    "slopeNumberClasses, " +
                    "engineeringGeologicalRockGroupNumberClasses, " +
                    "faultStructureNumberClasses, " +
                    "aspectNumberClasses");
        }
        compositionOperator.name = GH_SUSCEPTIBILITY_GHDSL_NAME;
        return compositionOperatorClient.submit(compositionOperator);
    }

    @GetMapping("/progress")
    public R<GeohazardComputationJob> currentProgress(Long jobId) {
        return compositionOperatorClient.jobStatus(jobId);
    }

    @GetMapping({
            "/layer-name",
            "/layerName"
    })
    public R<String> layerName(Long workingAreaId) {
        R<ResultRaster> latestResultRasterInfo = resultRasterClient.getLatestResultRasterInfo(workingAreaId,
                SUSCEPTIBILITY_FEATURE_NAME);

        String layerName = latestResultRasterInfo.getData().getLayerName();
        return R.ok(layerName);
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
