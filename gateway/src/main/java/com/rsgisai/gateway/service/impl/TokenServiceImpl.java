package com.rsgisai.gateway.service.impl;


import com.rsgisai.gateway.client.AuthClient;
import com.rsgisai.gateway.service.TokenService;
import com.rsgisai.geohazard.auth.util.JwtUtil;
import com.rsgisai.geohazard.system.common.R;
import io.jsonwebtoken.Jwt;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.io.Decoders;
import org.springframework.stereotype.Service;
import reactor.core.publisher.Mono;

import java.security.KeyFactory;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;

@Service
public class TokenServiceImpl implements TokenService {
    private final AuthClient authClient;

    private final int RETRY_COUNT = 2;
    private PublicKey publicKey;

    KeyFactory keyFactory;

    public TokenServiceImpl(AuthClient authClient) {
        this.authClient = authClient;
        {
            try {
                keyFactory = KeyFactory.getInstance("RSA");
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }
    }

    @Override
    public void updatePublicKey() throws InvalidKeySpecException {
        Mono<String> stringMono = authClient.fetchPublicKey();
        stringMono.subscribe(publicKeyString -> {
            try {
                publicKey = JwtUtil.parsePublicKey(publicKeyString);
            } catch (InvalidKeySpecException e) {
                throw new RuntimeException(e);
            }
        });
    }

    @Override
    public boolean validate(String jws) {
        for (int i = 0; i < RETRY_COUNT; i++) {
            try {
                Jwt parse = Jwts.parserBuilder()
                        .setSigningKey(publicKey)
                        .build()
                        .parse(jws);
                return true;
            } catch (Exception ignored) {
                try {
                    updatePublicKey();
                } catch (InvalidKeySpecException ignored1) {
                }
            }
        }
        return false;
    }
}
