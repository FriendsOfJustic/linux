package com.rsgisai.geohazard.system.common.util;

import org.junit.jupiter.api.Test;

import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

/**
 * @author tfh, created at 2023-04-12 10:33 PM
 */

public class StringReplacementTest {
    private static final Base64.Encoder encoder = Base64.getEncoder();
    private static String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }
    @Test
    void test1() throws NoSuchAlgorithmException {
        String s = "hello, +/ world.";

        s = s.replaceAll("\\+","-");
        s = s.replaceAll("/","_");

        System.out.println("s = " + s);
    }
}
