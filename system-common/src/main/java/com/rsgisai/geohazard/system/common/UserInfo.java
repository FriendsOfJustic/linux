package com.rsgisai.geohazard.system.common;

import lombok.Data;

@Data
public class UserInfo {
    private Long id;
    private String username;
    private String email;
    private String avatar;
    private Long currentWorkingArea;
}
