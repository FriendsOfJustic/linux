package com.rsgisai.geohazard.statistic;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableFeignClients
public class StatisticInfluenceApplication {
    public static void main(String[] args) {
        SpringApplication.run(StatisticInfluenceApplication.class, args);
    }
}
