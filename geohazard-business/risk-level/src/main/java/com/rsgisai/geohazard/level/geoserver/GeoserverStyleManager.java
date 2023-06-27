package com.rsgisai.geohazard.level.geoserver;

import it.geosolutions.geoserver.rest.GeoServerRESTPublisher;
import it.geosolutions.geoserver.rest.GeoServerRESTReader;

import java.net.MalformedURLException;

/**
 * @author tfh, created at 2023-02-20 2:32 PM
 */
public class GeoserverStyleManager {
    String RESTURL = "http://www.rsgisai.com:8080/geoserver";
    String RESTUSER = "admin";
    String RESTPW = "geoserver";
    GeoServerRESTReader reader = new GeoServerRESTReader(RESTURL, RESTUSER, RESTPW);
    GeoServerRESTPublisher publisher = new GeoServerRESTPublisher(RESTURL, RESTUSER, RESTPW);

    public GeoserverStyleManager() throws MalformedURLException {
    }

    public void publishStyle(String sldBody, String styleName) {
        publisher.publishStyle(sldBody, styleName);
    }
}
