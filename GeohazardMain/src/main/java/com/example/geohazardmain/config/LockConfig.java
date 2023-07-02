package com.example.geohazardmain.config;


import com.example.geohazardmain.Lock.GeohazardChainLock;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class LockConfig {

    @Bean
    public GeohazardChainLock GeohazardBeanConfig()
    {
        return new GeohazardChainLock();
    }
}
