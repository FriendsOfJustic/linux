package com.rsgisai.geohazard.statistic.feign;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@FeignClient("geohazard-sci")
//@RequestMapping// Feign 里面不可以写 RequestMapping
public interface CorrelationClient {
    @PostMapping("/geohazard-sci/correlation")
    List<List<Double>> correlation(@RequestBody List<List<Double>> data);

    @PostMapping("/geohazard-sci/correlation")
    Object correlationRaw(@RequestBody List<List<Double>> data);
}
