package com.rsgisai.geohazard.data.client;

import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.UserInfo;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpServletRequest;

@FeignClient("auth-service")// 注意不可以有斜线，即不要写成 '/auth-service'
public interface AuthClient {
    @GetMapping("/auth-service/auth/public_key")
    R<String> publicKey();

    @GetMapping("/auth-service/user-info")
    public R<UserInfo> getLoginUserInfo(
            @RequestParam(value = "username", required = false) String username);
}
