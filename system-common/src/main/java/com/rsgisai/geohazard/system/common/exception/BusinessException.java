package com.rsgisai.geohazard.system.common.exception;

/**
 * @author tfh, created at 2023-04-26 9:29 AM
 */
public class BusinessException extends RuntimeException{
    public BusinessException() {
    }

    public BusinessException(String message) {
        super(message);
    }
}
