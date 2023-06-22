package com.rsgisai.geohazard.system.common.util;

//import com.sun.corba.se.spi.servicecontext.SendingContextServiceContext;
import org.junit.jupiter.api.Test;

import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

/**
 * @author tfh, created at 2023-04-12 10:33 PM
 */

public class Md5Test {
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
        MessageDigest md = MessageDigest.getInstance("MD5");
        md.update("Hello, World! 你好，世界！".getBytes(StandardCharsets.UTF_8));
        int digestLength = md.getDigestLength();
        System.out.println("digestLength = " + digestLength);
        byte[] digest = md.digest();
        System.out.println("digest.length = " + digest.length);
        String s = encoder.encodeToString(digest);
        s = URLEncoder.encode(s);
        System.out.println("s = " + s);

        String s1 = bytesToHex(digest);
        System.out.println("s1 = " + s1);

    }
}
