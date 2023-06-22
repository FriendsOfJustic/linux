package com.rsgisai.geohazard.system.common.util;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.rsgisai.geohazard.system.common.ResultRaster;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.system.common.config.GeoserverConfig;

import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

/**
 * @author tfh, created at 2023-04-10 10:16 PM
 */
public class ResultRasterLayers {

    private static final ObjectMapper objectMapper = new ObjectMapper();
    private static final Base64.Encoder encoder = Base64.getEncoder();


    public static String hash(String text) {
        MessageDigest messageDigest;
        try {
            messageDigest = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
        byte[] md5code = messageDigest.digest(text.getBytes(StandardCharsets.UTF_8));
        String s = encoder.encodeToString(md5code);

        s = s.substring(0, s.length() - 2);

        s = s.replaceAll("\\+", "-");
        s = s.replaceAll("/", "_");

        return s;
    }

    /**
     * 参数处理
     * 要求：字母数字、下划线、横杠
     * 步骤：
     * 1. 获取参数JSON字符串
     * 2. 获取JSON字符串MD5码
     * 3. MD5码（128bit, 16byte），使用Base64将字节转换为可见字符
     * 5. 由于 MD5 16byte，Base64使用3byte一组4字符，（复杂推导）得到后面两个`=`为后缀，为了缩短长度去掉后面两个等号
     * 4. 将Base64的`+`号替换为`=`号，使用
     */
    public static String getLayerName(ResultRaster resultRaster) throws JsonProcessingException {
        String argsString = objectMapper.writeValueAsString(resultRaster.getArguments());

        String argsHash = hash(argsString);

        return resultRaster.feature
                + GeoserverConfig.LayerNameDELIMITER + resultRaster.workingAreaId
                + GeoserverConfig.LayerNameDELIMITER + argsHash;
    }
}
