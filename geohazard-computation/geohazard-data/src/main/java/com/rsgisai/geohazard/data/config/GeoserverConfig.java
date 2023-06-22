package com.rsgisai.geohazard.data.config;

import com.rsgisai.util.gis.util.geoserver.GeoserverRestManager;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

/**
 * @author tfh, created at 2023-04-13 8:51 AM
 */
@Configuration
public class GeoserverConfig {
    final GeoserverProperties geoserverProperties;

    public GeoserverConfig(GeoserverProperties geoserverProperties) {
        this.geoserverProperties = geoserverProperties;
    }

    @Bean
    public GeoserverRestManager geoserverManager() {
        return new GeoserverRestManager(
                geoserverProperties.getUsername(),
                geoserverProperties.getPassword(),
                geoserverProperties.getHostname(),
                geoserverProperties.getPort());
    }
}
