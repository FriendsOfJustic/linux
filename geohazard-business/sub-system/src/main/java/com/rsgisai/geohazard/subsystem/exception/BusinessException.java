package com.rsgisai.geohazard.subsystem.exception;

public class BusinessException extends RuntimeException {
    public BusinessException() {
    }

    public BusinessException(String s) {
        super(s);
    }

    public BusinessException(String message, Throwable cause) {
        super(message, cause);
    }
}
