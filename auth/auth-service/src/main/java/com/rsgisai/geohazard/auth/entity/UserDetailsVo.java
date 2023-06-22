package com.rsgisai.geohazard.auth.entity;

import lombok.Data;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;

@Data
public class UserDetailsVo {
    private String username;
    private String password;
    private String[] roles;

    public UserDetails toUserDetails() {
        return User.withUsername(this.getUsername())
                .password(this.getPassword())
                .roles(this.getRoles())
                .build();
    }
}
