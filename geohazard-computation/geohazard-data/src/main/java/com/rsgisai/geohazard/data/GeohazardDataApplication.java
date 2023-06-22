package com.rsgisai.geohazard.data;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

/**
 * @author tfh, created at 2023-04-10 9:53 AM
 */
@SpringBootApplication
@EnableFeignClients
public class GeohazardDataApplication {
    public static void main(String[] args) {
        SpringApplication.run(GeohazardDataApplication.class, args);
    }
}
