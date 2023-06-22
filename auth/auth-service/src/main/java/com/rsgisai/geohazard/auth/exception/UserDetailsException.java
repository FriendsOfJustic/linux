package com.rsgisai.geohazard.auth.exception;

public class UserDetailsException extends BusinessException {
    public UserDetailsException() {
    }

    public UserDetailsException(String s) {
        super(s);
    }


    public UserDetailsException(String message, Throwable cause) {
        super(message, cause);
    }
}
