package com.rsgisai.test;

import java.nio.charset.StandardCharsets;
import java.util.Base64;

/**
 * @author tfh, created at 2023-04-10 10:10 PM
 */
public class Base64Test {
    public static void main(String[] args) {
        Base64.Decoder decoder = Base64.getDecoder();
        Base64.Encoder encoder = Base64.getEncoder();
        String s = encoder.encodeToString("你好".getBytes(StandardCharsets.UTF_8));
        System.out.println("s = " + s);
    }
}
