package com.rsgisai.geohazard.system.common.util;

/**
 * @author tfh, created at 2023-04-13 9:20 PM
 */
public class DevelopmentUtil {
    public static DevelopmentException tobeImplemented(String methodName) {
        return new DevelopmentException(methodName + " to be implemented!");
    }
}
