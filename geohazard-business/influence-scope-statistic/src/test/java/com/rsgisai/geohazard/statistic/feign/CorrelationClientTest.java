package com.rsgisai.geohazard.statistic.feign;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;


@SpringBootTest
class CorrelationClientTest {
    @Resource
    private CorrelationClient correlationClient;

    @Resource
    @Test
    void correlationRaw() {
    }
}