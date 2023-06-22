package com.rsgisai.geohazard.system.common.exception;

/**
 * @author tfh, created at 2023-04-14 4:13 PM
 */
public class FeatureNotSupportedException extends RuntimeException {
    public FeatureNotSupportedException(String feature, String message) {
        super(message +
                ", feature \"" + feature + "\" is currently not supported");
    }
}
