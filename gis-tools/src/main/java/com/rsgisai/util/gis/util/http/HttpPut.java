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
public class HttpPut {
    String username;
    String password;
    String contentType;
    String urlString;
    InputStream body;

    public String doPut() throws IOException {
        String authString = username + ":" + password;
        String authStringEnc = Base64.getEncoder().encodeToString(authString.getBytes());

        URL url = new URL(this.urlString);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("PUT");
        connection.setRequestProperty("Content-Type", contentType);
        connection.setRequestProperty("Authorization", "Basic " + authStringEnc);
        connection.setDoOutput(true);

        StringBuilder response;
        try (OutputStream outputStream = connection.getOutputStream()) {
            InputOutputStreamUtil.copy(body, outputStream);// copy() will flush outputStream

            int responseCode = connection.getResponseCode();
            System.out.println("Response code: " + responseCode);

            try (InputStream inputStream = connection.getInputStream();
                 BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
            ) {
                String line;
                response = new StringBuilder();
                while ((line = reader.readLine()) != null) {
                    response.append(line);
                    response.append(System.getProperty("line.separator"));
                }
            }
        }
        return response.toString();
    }
}
