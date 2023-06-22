package com.rsgisai.geohazard.data.config;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.autoconfigure.jdbc.DataSourceProperties;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

import javax.sql.DataSource;


@Configuration
public class DataSourceConfig {
	
	@Primary
    @Bean(name = "mysqlDataSourceProperties")
    @ConfigurationProperties(prefix = "spring.datasource.mysql")
	DataSourceProperties mysqlDataSourceProperties() {
        return new DataSourceProperties();
	}

    @Primary
    @Bean(name = "mysqlDataSource")
    public DataSource mysqlDataSource(@Qualifier("mysqlDataSourceProperties") DataSourceProperties dataSourceProperties) {
        return dataSourceProperties.initializeDataSourceBuilder().build();
    }

    @Bean(name = "pgsqlDataSourceProperties")
    @ConfigurationProperties(prefix = "spring.datasource.pgsql")
    DataSourceProperties pgsqlDataSourceProperties() {
        return new DataSourceProperties();
    }

    @Bean(name = "pgsqlDataSource")
    public DataSource pgsqlDataSource(@Qualifier("pgsqlDataSourceProperties") DataSourceProperties dataSourceProperties) {
        return dataSourceProperties.initializeDataSourceBuilder().build();
    }
    
}
