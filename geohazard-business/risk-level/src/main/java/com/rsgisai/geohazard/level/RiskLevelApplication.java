package com.rsgisai.geohazard.level;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

/**
 * @author tfh, created at 2023-02-09 3:58 PM
 */
@SpringBootApplication
@EnableFeignClients
public class RiskLevelApplication {
    public static void main(String[] args) {
        SpringApplication.run(RiskLevelApplication.class, args);
    }
}
