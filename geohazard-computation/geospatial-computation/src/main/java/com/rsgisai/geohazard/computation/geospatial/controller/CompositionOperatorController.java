package com.rsgisai.geohazard.computation.geospatial.controller;

import com.rsgisai.geohazard.computation.geospatial.service.CompositionOperatorService;
import com.rsgisai.geohazard.computation.geospatial.service.CompositionOperatorServiceAsync;
import com.rsgisai.geohazard.computation.geospatial.service.impl.CompositionOperatorServiceSyncImpl;
import com.rsgisai.geohazard.computation.geospatial.service.impl.CompositionOperatorServiceAsyncImpl;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.computation.geospatial.service.GeohazardComputationJobService;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

@RestController
@RequestMapping("/composition-operator")
public class CompositionOperatorController {
    @Autowired
    private CompositionOperatorService compositionOperatorServiceSync;

    @Autowired
    private CompositionOperatorServiceAsync compositionOperatorServiceAsync;

    @Autowired
    private GeohazardComputationJobService geohazardComputationJobService;

    /**
     * 目前只实现了通过 name 进行查询
     */
    @GetMapping
    public R<CompositionOperator> getGhdsl(CompositionOperator compositionOperator) {
        compositionOperator = compositionOperatorServiceSync.query(compositionOperator);
        return R.ok(compositionOperator);
    }

    @PostMapping
    public R<String> addCompOperator(@RequestBody CompositionOperator compositionOperator) {
        String name = compositionOperator.name;
        String dsl = compositionOperator.dsl;
        compositionOperatorServiceSync.verifyDsl(dsl);
        compositionOperatorServiceSync.add(compositionOperator);
        return R.success("ok").message("添加复合算子 '" + name + "' 成功");
    }

    @PutMapping
    public R<CompositionOperator> updateCompOperator(@RequestBody CompositionOperator compositionOperator) {
        String name = compositionOperator.name;
        String dsl = compositionOperator.dsl;
        compositionOperatorServiceSync.verifyDsl(dsl);
        compositionOperatorServiceSync.update(compositionOperator);
        return R.success(compositionOperator).message("更新复合算子 '" + name + "' 成功");
    }

    @PostMapping("/submit")
    public R<GeohazardComputationJob> submit(@RequestBody CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException, ExecutionException, InterruptedException {
        GeohazardComputationJob geohazardComputationJob = new GeohazardComputationJob();
        geohazardComputationJob.name = compositionOperator.name;
        geohazardComputationJob.status = "ready";
        geohazardComputationJob.currentLine = 0;
        geohazardComputationJob.createBy = compositionOperator.userId;
        geohazardComputationJob.modifyBy = compositionOperator.userId;

        if (geohazardComputationJobService.add(geohazardComputationJob) > 0) {

            // execute asynchronously
            compositionOperator.jobId = geohazardComputationJob.id;
            CompletableFuture<Long> execute = compositionOperatorServiceAsync.execute(compositionOperator);

            return R.ok(geohazardComputationJob);
        } else {
            throw new RuntimeException("submit failed");
        }
    }

    /**
     * 阻塞操作，直到算子执行结束才会返回。
     *
     * @param compositionOperator
     * @return
     * @throws IOException
     * @throws InvocationTargetException
     * @throws IllegalAccessException
     */
    @PostMapping("/operate")
    public R<?> invokeOperator(@RequestBody CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException {
        compositionOperatorServiceSync.operate(compositionOperator);
        return R.success("ok").message("执行复合算子 '" + compositionOperator.name + "' 成功");
    }

    @GetMapping("/job/progress")
    public R<Integer> steps(Long jobId) {
        GeohazardComputationJob geohazardComputationJob = geohazardComputationJobService.query(jobId);
        return R.success(geohazardComputationJob.currentLine);
    }

    @GetMapping("/job/status")
    public R<GeohazardComputationJob> jobStatus(Long jobId) {
        GeohazardComputationJob geohazardComputationJob = geohazardComputationJobService.query(jobId);
        if (geohazardComputationJob == null) {
            return R.fail(geohazardComputationJob, "No such Job#" + jobId);
        }
        return R.success(geohazardComputationJob);
    }
}
