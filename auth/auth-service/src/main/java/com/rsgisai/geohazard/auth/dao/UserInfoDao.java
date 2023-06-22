package com.rsgisai.geohazard.auth.dao;

import com.rsgisai.geohazard.system.common.UserInfo;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserInfoDao {
    UserInfo selectByUsername(String username);
}
