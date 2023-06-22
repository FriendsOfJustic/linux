package com.example.sys.service.impl;


import com.example.sys.service.FloodInfluenceAreaService;
import org.springframework.stereotype.Service;

import java.io.*;
import java.math.BigInteger;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Base64;
import java.util.concurrent.atomic.AtomicInteger;

@Service
public class FloodInfluenceAreaImpl implements FloodInfluenceAreaService {
    @Override
    public String AlgorithmCall(Integer x, Integer y, Integer H, BigInteger Q) throws IOException {
        String urlString = "http://122.112.145.250:20236/?";
        URL url=new URL(urlString);
        System.out.println(urlString);
        HttpURLConnection httpCon=(HttpURLConnection) url.openConnection();
        httpCon.setDoOutput(true);
        httpCon.setRequestProperty("Content-Type", "application/json");
        httpCon.setRequestProperty("Accept", "application/json");
        httpCon.setRequestMethod("GET");

        String requestBody = "$/geohazard/data$"+x.toString()+"$"+y.toString()+"$"+H.toString()+"$"+Q.toString()+"$";
        OutputStream outputStream = httpCon.getOutputStream();
        outputStream.write(requestBody.getBytes());
        outputStream.flush();

        httpCon.connect();
        int responseCode = httpCon.getResponseCode();
        String wkbstring=httpCon.getResponseMessage();
        System.out.println("响应状态"+responseCode);
        System.out.println("响应消息"+wkbstring);
        // 读取响应
        BufferedReader reader = new BufferedReader(new InputStreamReader(httpCon.getInputStream()));
        String line;
        StringBuilder response = new StringBuilder();
        while ((line = reader.readLine()) != null) {
            response.append(line);
        }
        reader.close();

        // 输出响应
        System.out.println(response.toString());

        return null;

    }





}
