package com.rsgisai.geohazard.subsystem.service.impl;

import com.rsgisai.geohazard.subsystem.service.GeoserverService;
import it.geosolutions.geoserver.rest.GeoServerRESTPublisher;
import it.geosolutions.geoserver.rest.GeoServerRESTReader;
import org.springframework.stereotype.Service;

import java.net.MalformedURLException;

/**
 * @author tfh, created at 2023-02-19 10:37 PM
 */
@Service
public class GeoserverServiceImpl implements GeoserverService {

    private final GeoServerRESTReader reader;
    private final GeoServerRESTPublisher publisher;

    public GeoserverServiceImpl() throws MalformedURLException {
        String RESTURL = "http://www.rsgisai.com:8080/geoserver";
        String RESTUSER = "admin";
        String RESTPW = "geoserver";

        reader = new GeoServerRESTReader(RESTURL, RESTUSER, RESTPW);
        publisher = new GeoServerRESTPublisher(RESTURL, RESTUSER, RESTPW);
    }

    @Override
    public void createStyle() {

    }
}
