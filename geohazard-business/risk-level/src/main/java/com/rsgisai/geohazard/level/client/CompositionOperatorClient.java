package com.rsgisai.geohazard.level.client;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

@FeignClient("geospatial-computation")// 注意不可以有斜线，即不要写成 '/geospatial-computation'
public interface CompositionOperatorClient {
    /**
     * 如果没有怎么处理？异常？
     */
    @GetMapping("/geospatial-computation/composition-operator")
//    R<CompositionOperator> getGhdsl(CompositionOperator compositionOperator);// 错误写法，会造成OpenFeign发送POST请求
    R<CompositionOperator> getGhdsl(@RequestParam("name") String name);// 正确写法，正确发送 name 参数，发送GET请求

    @PutMapping("/geospatial-computation/composition-operator")
    R<CompositionOperator> update(CompositionOperator compositionOperator);


    @PostMapping("/geospatial-computation/composition-operator/execute")
    R<GeohazardComputationJob> execute(@RequestBody CompositionOperator compositionOperator);

    /**
     * 非阻塞操作，提交一个任务，返回任务ID，通过任务ID进行任务进度监控
     *
     * @param compositionOperator
     * @return
     */
    @PostMapping("/geospatial-computation/composition-operator/submit")
    R<GeohazardComputationJob> submit(@RequestBody CompositionOperator compositionOperator);

    @GetMapping("/geospatial-computation/composition-operator/job/status")
    R<GeohazardComputationJob> jobStatus(
            @RequestParam("jobId") /* 必须添加 @RequestParam 注解，否则发送的是 POST 请求 */
                    Long jobId);

    @PostMapping("/geospatial-computation/composition-operator")
    R<String> addCompOperator(@RequestBody CompositionOperator compositionOperator);

}
