package com.example.sys.config;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-04-13 8:56 AM
 */
@Data
@Component //交给spring代理
@ConfigurationProperties(prefix = "geoserver") //@ConfigurationProperties注解用于自动配置绑定，可以将application.properties配置中的值注入到bean对象上。
public class GeoserverProperties {
    private String username;
    private String password;
    private String hostname;
    private Integer port;
}
