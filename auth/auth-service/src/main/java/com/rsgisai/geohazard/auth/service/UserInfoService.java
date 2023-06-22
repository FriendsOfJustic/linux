package com.rsgisai.geohazard.auth.service;

import com.rsgisai.geohazard.system.common.UserInfo;

import javax.servlet.http.HttpServletRequest;
import java.security.SignatureException;

public interface UserInfoService {
    UserInfo loginUserInfo(String jwt) throws SignatureException;

    UserInfo queryUserInfoByUsername(String username);

}
