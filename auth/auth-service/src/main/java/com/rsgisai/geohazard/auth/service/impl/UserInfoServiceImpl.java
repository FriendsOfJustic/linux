package com.rsgisai.geohazard.auth.service.impl;

import com.rsgisai.geohazard.auth.dao.UserInfoDao;
import com.rsgisai.geohazard.auth.exception.UserInfoException;
import com.rsgisai.geohazard.auth.service.TokenService;
import com.rsgisai.geohazard.auth.service.UserInfoService;
import com.rsgisai.geohazard.system.common.UserInfo;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.stereotype.Service;

import java.security.SignatureException;

@Service
public class UserInfoServiceImpl implements UserInfoService {
    private final TokenService tokenService;
    private final UserInfoDao userInfoDao;

    public UserInfoServiceImpl(TokenService tokenService, UserInfoDao userInfoDao) {
        this.tokenService = tokenService;
        this.userInfoDao = userInfoDao;
    }


    @Override
    public UserInfo loginUserInfo(String jwt) throws SignatureException {
        UserDetails userDetails = tokenService.parseUserDetails(jwt);
        String username = userDetails.getUsername();
        UserInfo userInfo = userInfoDao.selectByUsername(username);
        if (userInfo == null) throw new UserInfoException("user:'" + username + "' dose not exist.");
        return userInfo;
    }

    @Override
    public UserInfo queryUserInfoByUsername(String username) {
        return userInfoDao.selectByUsername(username);
    }
}
