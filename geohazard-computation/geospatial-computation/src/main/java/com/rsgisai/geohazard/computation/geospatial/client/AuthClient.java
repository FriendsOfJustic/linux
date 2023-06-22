package com.rsgisai.geohazard.computation.geospatial.client;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

@FeignClient("auth-service")// 注意不可以有斜线，即不要写成 '/auth-service'
public interface AuthClient {
    @GetMapping("/auth-service/auth/public_key")
    R<String> publicKey();
}
