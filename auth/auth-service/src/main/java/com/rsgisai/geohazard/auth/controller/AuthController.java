package com.rsgisai.geohazard.auth.controller;

import com.rsgisai.geohazard.auth.service.TokenService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/auth")
public class AuthController {
    private final TokenService tokenService;

    public AuthController(TokenService tokenService) {
        this.tokenService = tokenService;
    }

    @GetMapping("/public_key")
    public R<String> publicKey() {
        return R.success("获取 Public Key 成功").data(
                tokenService.getPublicKeyString());
    }
}
