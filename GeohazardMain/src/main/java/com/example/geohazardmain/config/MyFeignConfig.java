package com.example.geohazardmain.config;

import feign.Request;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class MyFeignConfig {
    @Bean
    public Request.Options requestOptions() {
        return new Request.Options(300000, 10000); // 设置连接超时时间为5min，读取超时时间为10秒
    }
}
