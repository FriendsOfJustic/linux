package com.rsgisai.util.gis.util.http;

/**
 * @author tfh, created at 2023-02-16 3:58 PM
 */
public class HttpUtil {
    public static HttpGet.HttpGetBuilder get() {
        return HttpGet.builder();
    }
    public static HttpPut.HttpPutBuilder put() {
        return HttpPut.builder();
    }
}
