package com.rsgisai.geohazard.auth;

import org.springframework.security.core.AuthenticationException;

/**
 * @author tfh, created at 2023-05-16 9:42 PM
 */
public class TokenNotProvidedException extends AuthenticationException {
    public TokenNotProvidedException(String msg, Throwable cause) {
        super(msg, cause);
    }

    public TokenNotProvidedException(String msg) {
        super(msg);
    }

    public TokenNotProvidedException() {
        super("token not provided");
    }
}
