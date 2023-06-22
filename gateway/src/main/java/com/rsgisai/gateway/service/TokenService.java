package com.rsgisai.gateway.service;

import reactor.core.publisher.Mono;

import java.security.spec.InvalidKeySpecException;

public interface TokenService {

    void updatePublicKey() throws InvalidKeySpecException;

    boolean validate(String jws);

}
