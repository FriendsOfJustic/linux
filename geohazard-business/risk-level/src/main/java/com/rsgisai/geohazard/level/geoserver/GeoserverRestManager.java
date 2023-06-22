package com.rsgisai.geohazard.level.geoserver;

import com.rsgisai.util.gis.util.geoserver.exception.style.StyleNotFoundException;
import com.rsgisai.util.gis.util.http.HttpGet;
import com.rsgisai.util.gis.util.http.HttpPut;
import com.rsgisai.util.gis.util.http.HttpUtil;
import org.springframework.beans.factory.annotation.Value;

import java.io.ByteArrayInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.Base64;

public class GeoserverRestManager {
    @Value("${geoserverURL.IP}")
    String hostname;

    @Value("${geoserverURL.PORT}")
    int port;
    String username;
    String password;

    public GeoserverRestManager(String username, String password,
                                String hostname, int port) {
        this.hostname = hostname;
        this.port = port;
        this.username = username;
        this.password = password;
    }


    public String uploadGeoTiff(String workspace, String layerName, InputStream tiff) throws IOException {
        String urlString = String.format("http://%s:%d/geoserver/rest/workspaces/%s/coveragestores/%s/file.geotiff",
                hostname, port, workspace, layerName);
        HttpPut httpPut = HttpUtil.put()
                .urlString(urlString)
                .username(username)
                .password(password)
                .contentType("image/tiff")
                .body(tiff)
                .build();
        return httpPut.doPut();
    }


    //删除指定工作区的指定图层
    public Boolean DeleteDataStores(String workspace, String layerName) throws IOException {
        // geohazard-geoserver  改成路径
        String urlString = String.format("http://%s:%d/geoserver/rest/workspaces/%s/coveragestores/%s?recurse=true",
                hostname, port,workspace, layerName);
        String authString = username + ":" + password;
        String authStringEnc = Base64.getEncoder().encodeToString(authString.getBytes());
        URL url=new URL(urlString);
        System.out.println(urlString);
        HttpURLConnection httpCon=(HttpURLConnection) url.openConnection();
        httpCon.setDoOutput(true);
        httpCon.setRequestProperty("Content-Type", "application/json");
        httpCon.setRequestProperty("Accept", "application/json");
        httpCon.setRequestProperty("Authorization", "Basic " + authStringEnc);
        httpCon.setRequestMethod("DELETE");
        httpCon.connect();
        int responseCode = httpCon.getResponseCode();
        System.out.println(responseCode);
        if(responseCode==200)
            return true;
        else
            return false;
    }

    public void setLayerStyle(String workspace,
                              String layerName,
                              String styleName) throws IOException {

        // check if style exist
        if (!styleExist(workspace, styleName))
            throw new StyleNotFoundException(workspace, styleName);

        // get origin layer descriptor
        String urlString = String.format("http://%s:%d/geoserver/rest/layers/%s",  hostname, port,layerName);
        HttpGet httpGet = HttpUtil.get()
                .urlString(urlString)
                .username(username)
                .password(password)
                .accept("application/json")
                .build();
        String originalLayerSetting = httpGet.doGet();
        System.out.println("originalLayerSetting = " + originalLayerSetting);
        String stylingLayerSetting = originalLayerSetting.replace("raster", styleName);
        System.out.println("stylingLayerSetting = " + stylingLayerSetting);

        // change style and push layer descriptor
        HttpUtil.put()
                .urlString(urlString)
                .username(username)
                .password(password)
                .contentType("application/json")
                .body(new ByteArrayInputStream(stylingLayerSetting.getBytes(StandardCharsets.UTF_8)))
                .build()
                .doPut();
    }

    /**
     * tested
     */
    public boolean styleExist(String workspace, String styleName) throws IOException {
        try {
            getStyleInfo(workspace, styleName);
            return true;
        } catch (StyleNotFoundException e) {
            return false;
        }
    }

    public String getStyleInfo(String workspace, String styleName) throws IOException {
        String urlString =
                String.format("http://%s:%d/geoserver/rest/workspaces/%s/styles/%s",
                        hostname,
                        port,
                        workspace,
                        styleName);
        HttpGet httpGet = HttpUtil.get()
                .urlString(urlString)
                .username(username)
                .password(password)
                .accept("application/json")
                .build();
        String styleInfo;
        try {
            styleInfo = httpGet.doGet();
        } catch (FileNotFoundException e) {
            throw new StyleNotFoundException(workspace, styleName);
        }
        return styleInfo;
    }
}
