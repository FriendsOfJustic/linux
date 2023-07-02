package com.example.geohazardmain;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.scheduling.annotation.EnableScheduling;

@SpringBootApplication
//@EnableScheduling
@EnableFeignClients
public class GeohazardMainApplication {
    public static void main(String[] args) {

        SpringApplication.run(GeohazardMainApplication.class, args);

    }

}
