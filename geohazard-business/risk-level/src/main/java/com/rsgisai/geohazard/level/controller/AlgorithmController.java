package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.dao.pgsql.EvaluationAlgorithmDao;
import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;
import com.rsgisai.geohazard.level.service.AlgorithmService;
import com.rsgisai.geohazard.level.service.CurvatureAlgorithmService;
import com.rsgisai.geohazard.level.service.impl.PublishServiceImpl;
import com.rsgisai.geohazard.system.common.R;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;

/**
 * @author tfh, created at 2023-02-14 10:35 AM
 */
@RestController
public class AlgorithmController {
    @Autowired
    private AlgorithmService algorithmService;
    @Autowired
    private CurvatureAlgorithmService curvatureAlgorithmService;
    @Qualifier("evaluationAlgorithmDao")
    @Autowired
    private EvaluationAlgorithmDao evaluationAlgorithmDao;
    @Autowired
    private PublishServiceImpl publishService;

    @PostMapping("calculate-all-derived")
    public R<String> calculateAllDerived(Long workingAreaId) {
        // todo
        algorithmService.calculateAllDerived(workingAreaId);
        return R.success("成功");
    }

    @PostMapping("calculate-derived")
    public R<String> calculateDerived(Long workingAreaId, String feature) {
        algorithmService.calculateDerived(workingAreaId, feature);
        return R.success("calculate success.");
    }

    @PostMapping("reclassify")
    public R<String> reclassify(
            @RequestParam("workingAreaId") long workingAreaId,
            @RequestParam("feature") String feature,
            @RequestParam("numberClasses") int numberClasses
    ) throws SusceptibilityAlgorithmException {
        algorithmService.reclassify(workingAreaId, feature, numberClasses);
        return R.success("reclassify success.");
    }

    @PostMapping("calculateEachXxl")
    public R<String> calculateEachXxl(
            @RequestParam("workingAreaId") long workingAreaId,
            @RequestParam("numberClasses") int numberClasses
    ) throws SusceptibilityAlgorithmException, IOException {
        algorithmService.generateXxlInRaster(workingAreaId, numberClasses);
        return R.success("calculateTotalXxl success.");
    }

    @PostMapping("calculateTotalXxl")
    public R<String> calculateTotalXxl(
            @RequestParam("workingAreaId") long workingAreaId,
            @RequestParam("demNumberClasses") Integer demNumberClasses,
            @RequestParam("slopeNumberClasses") Integer slopeNumberClasses,
            @RequestParam("aspectNumberClasses") Integer aspectNumberClasses,
            @RequestParam("curvatureNumberClasses") Integer curvatureNumberClasses
    ) {
        evaluationAlgorithmDao.calculateTotalInformationAmount(
                workingAreaId, demNumberClasses, slopeNumberClasses, aspectNumberClasses, curvatureNumberClasses);
        return R.success("calculateTotalXxl success.");
    }

    @PostMapping("calculateEvaluation")
    public R<String> calculateEvaluation(
            @RequestParam("workingAreaId") long workingAreaId,
            @RequestParam("outNumberClasses") Integer outNumberClasses,
            @RequestParam("demNumberClasses") Integer demNumberClasses,
            @RequestParam("slopeNumberClasses") Integer slopeNumberClasses,
            @RequestParam("aspectNumberClasses") Integer aspectNumberClasses,
            @RequestParam("curvatureNumberClasses") Integer curvatureNumberClasses
    ) throws SusceptibilityAlgorithmException, IOException {
        algorithmService.calculateEvaluation(
                workingAreaId,
                demNumberClasses,
                slopeNumberClasses,
                aspectNumberClasses,
                curvatureNumberClasses,
                outNumberClasses);
        publishService.publishSusceptibility(
                workingAreaId,
                outNumberClasses,
                demNumberClasses,
                slopeNumberClasses,
                aspectNumberClasses,
                curvatureNumberClasses
        );
        return R.success("calculateEvaluation success.");
    }

}
