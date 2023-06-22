package com.rsgisai.geohazard.statistic.service;

import com.rsgisai.geohazard.entity.Correlation;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;
import java.util.List;

@SpringBootTest
class LandslideServiceTest {
    @Resource
    private LandslideService landslideService;

    @Test
    void correlation() {
        Correlation correlation = landslideService.correlation();
        System.out.println(correlation);
        for (List<Double> doubles : correlation.getMatrix()) {
            System.out.println(doubles);
        }
    }
}