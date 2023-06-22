package com.rsgisai.geohazard.data.service.impl;

import com.rsgisai.geohazard.auth.util.JwtUtil;
import com.rsgisai.geohazard.data.client.AuthClient;
import com.rsgisai.geohazard.data.service.AuthService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.UserInfo;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContext;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import java.security.PublicKey;
import java.security.spec.InvalidKeySpecException;

/**
 * @author tfh, created at 2023-05-16 9:47 PM
 */
@Service
public class AuthServiceImpl implements AuthService {
    private final AuthClient authClient;
    private PublicKey publicKey;

    public AuthServiceImpl(AuthClient authClient) {
        this.authClient = authClient;
    }

    @Override
    public PublicKey getPublicKey() {
        if (this.publicKey == null) {
            return getLatestPublicKey();
        }
        return publicKey;
    }

    @Override
    public String getCurrentUsername() {
        SecurityContext context = SecurityContextHolder.getContext();
        Authentication authentication = context.getAuthentication();
        return (String) authentication.getPrincipal();
    }

    @Override
    public Long getCurrentUserId() {
        R<UserInfo> loginUserInfo = authClient.getLoginUserInfo(getCurrentUsername());
        UserInfo userInfo = loginUserInfo.getData();
        return userInfo.getId();
    }

    @Override
    public PublicKey getLatestPublicKey() {
        R<String> publicKeyR = authClient.publicKey();
        String encodedPublicKey = publicKeyR.getData();
        try {
            this.publicKey = JwtUtil.parsePublicKey(encodedPublicKey);
        } catch (InvalidKeySpecException e) {
            throw new RuntimeException(e);
        }
        return this.publicKey;
    }
}
