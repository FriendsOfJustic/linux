package com.rsgisai.geohazard.system.common.config;

/**
 * @author tfh, created at 2023-04-13 9:29 PM
 */
public class GeoserverConfig {
    public static String username = "admin";
    public static String password = "geoserver";
    public static String hostname = "www.rsgisai.com";
    public static int port = 8080;


    /**
     * 如果用 "." 的话会有 bug，当 REST 请求的最后面参数有 "." 就会出问题
     */
    public static final String LayerNameDELIMITER = "-";
    public static final String StyleNameDELIMITER = "-";
}
