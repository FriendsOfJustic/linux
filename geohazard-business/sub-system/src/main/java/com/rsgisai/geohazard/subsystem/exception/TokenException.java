package com.rsgisai.geohazard.subsystem.exception;

import java.security.spec.InvalidKeySpecException;

public class TokenException extends RuntimeException {
    public TokenException(Exception e) {
        super(e);
    }

    public TokenException(String message) {
        super(message);
    }
}
