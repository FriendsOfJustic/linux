package com.rsgisai.util.gis.util.http;

import lombok.Builder;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * @author tfh, created at 2023-02-16 3:48 PM
 */
@Builder
public class HttpRequest {
    String method;

    public static String post() throws IOException {
        URL url = new URL("https://example.com/api/endpoint");
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("POST");
        connection.setRequestProperty("Content-Type", "application/json");
        connection.setDoOutput(true);

        String requestBody = "{\"key1\":\"value1\",\"key2\":\"value2\"}";
        OutputStream outputStream = connection.getOutputStream();
        outputStream.write(requestBody.getBytes());
        outputStream.flush();

        int responseCode = connection.getResponseCode();
        System.out.println("Response code: " + responseCode);

        InputStream inputStream = connection.getInputStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        String line;
        StringBuffer response = new StringBuffer();
        while ((line = reader.readLine()) != null) {
            response.append(line);
        }
        reader.close();

        return response.toString();
    }
}
