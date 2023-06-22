package com.rsgisai.geohazard.auth.controller;

import com.rsgisai.geohazard.auth.service.UserInfoService;
import com.rsgisai.geohazard.system.common.UserInfo;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpServletRequest;
import java.security.SignatureException;

@RestController
@RequestMapping("/user-info")
public class UserInfoController {
    @Autowired
    private UserInfoService userInfoService;

    @GetMapping
    public R<UserInfo> getLoginUserInfo(
            @RequestParam(value = "username", required = false) String username,
            HttpServletRequest request) throws SignatureException {
        UserInfo userInfo;
        if (username == null) {
            String token = request.getHeader("token");
            userInfo = userInfoService.loginUserInfo(token);
        } else {
            userInfo = userInfoService.queryUserInfoByUsername(username);
        }
        return R.success(userInfo);
    }
}
