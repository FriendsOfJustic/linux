package com.rsgisai.geohazard.auth.service;

import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;

import java.security.SignatureException;
import java.util.Collection;

public interface TokenService {
    String generate(String username, Collection<? extends GrantedAuthority> authorities);

    String getPublicKeyString();

    void updateKeyPair();

    boolean validate(String jws, String publicKeyString);

    boolean validate(String jws);

    UserDetails parseUserDetails(String jws) throws SignatureException;
}
