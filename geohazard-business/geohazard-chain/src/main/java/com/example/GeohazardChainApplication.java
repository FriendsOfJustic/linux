package com.example;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.example.sys.mapper")
public class GeohazardChainapplication {
    public static void main(String[] args) {
        SpringApplication.run(GeohazardChainapplication.class,args);
    }
}
