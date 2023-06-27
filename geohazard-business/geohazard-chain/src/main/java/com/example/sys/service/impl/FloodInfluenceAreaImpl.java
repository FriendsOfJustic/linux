package com.example.sys.service.impl;


import com.example.sys.service.FloodInfluenceAreaService;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.io.*;
import java.math.BigInteger;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.Base64;
import java.util.concurrent.atomic.AtomicInteger;

@Service
public class FloodInfluenceAreaImpl implements FloodInfluenceAreaService {

    @Value("${Module4.PATH}")
    String PATH;
    @Override
    public String AlgorithmCall(Integer x, Integer y, Integer H, BigInteger Q) throws IOException {


        System.out.println("绝对路径"+PATH);

        //设置url 这里非常的奇怪 参数居然都放在url 中搞的非常炸裂。正常post请求都要放在请求体body中
        String urlString = String.format("http://101.43.165.61:666/py-influence-scope-statistic/other_produce/get_flow_direction?input_file=%s" +
                "&start_x=%s&start_y=%s&bay_height=%s&Q=%s", URLEncoder.encode(PATH),URLEncoder.encode(Integer.toString(x))
                ,URLEncoder.encode(Integer.toString(y)),URLEncoder.encode(Integer.toString(H)),URLEncoder.encode(Q.toString()));


        System.out.println("发送的路径"+urlString);

        URL url=new URL(urlString);
        System.out.println("url设置为"+urlString);
        HttpURLConnection httpCon=(HttpURLConnection) url.openConnection();
//        httpCon.setDoOutput(true);
        httpCon.setRequestProperty("Accept", "application/json");
        httpCon.setRequestMethod("POST");
        httpCon.connect();
        BufferedReader in = new BufferedReader(new InputStreamReader(httpCon.getInputStream()));
        String inputLine;
        StringBuffer response = new StringBuffer();
        while ((inputLine = in.readLine()) != null) {
            response.append(inputLine);
        }
        in.close();
        System.out.println(response.toString());
        return null;

    }





}
