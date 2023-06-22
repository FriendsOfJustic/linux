package com.rsgisai.geohazard.data.service;

import java.security.PublicKey;

/**
 * @author tfh, created at 2023-05-16 9:47 PM
 */
public interface AuthService {
    PublicKey getPublicKey();

    String getCurrentUsername();
    Long getCurrentUserId();

    PublicKey getLatestPublicKey();
}
