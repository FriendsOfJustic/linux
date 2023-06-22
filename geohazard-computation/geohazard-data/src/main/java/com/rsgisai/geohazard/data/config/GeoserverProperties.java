package com.rsgisai.geohazard.data.config;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-04-13 8:56 AM
 */
@Data
@Component
@ConfigurationProperties(prefix = "geoserver")
public class GeoserverProperties {
    private String username;
    private String password;
    private String hostname;
    private Integer port;
}
