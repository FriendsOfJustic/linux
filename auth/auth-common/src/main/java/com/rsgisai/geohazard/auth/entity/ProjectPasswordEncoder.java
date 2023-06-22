package com.rsgisai.geohazard.auth.entity;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.factory.PasswordEncoderFactories;
import org.springframework.security.crypto.password.PasswordEncoder;

public class ProjectPasswordEncoder {
    private ProjectPasswordEncoder() {
    }

    public static PasswordEncoder getPasswordEncoder() {
//        return new BCryptPasswordEncoder();
        return PasswordEncoderFactories.createDelegatingPasswordEncoder();// 支持多种类型的加密方式
    }
}
