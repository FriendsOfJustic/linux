package com.rsgisai.util.gis.util.http;

import com.rsgisai.util.gis.util.InputOutputStreamUtil;
import lombok.Builder;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Base64;

/**
 * @author tfh, created at 2023-02-16 3:56 PM
 */
@Builder
public class HttpGet {
    String username;
    String password;
    String accept;
    String urlString;

    public String doGet() throws IOException {
        String authString = username + ":" + password;
        String authStringEnc = Base64.getEncoder().encodeToString(authString.getBytes());

        URL url = new URL(this.urlString);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");
        connection.setRequestProperty("Accept", accept);
        connection.setRequestProperty("Authorization", "Basic " + authStringEnc);
        connection.setDoOutput(true);


        int responseCode = connection.getResponseCode();
        System.out.println("Response code: " + responseCode);

        try (InputStream inputStream = connection.getInputStream();
             BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        ) {
            StringBuilder response = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                response.append(line);
                response.append(System.getProperty("line.separator"));
            }
            return response.toString();
        }
    }
}
