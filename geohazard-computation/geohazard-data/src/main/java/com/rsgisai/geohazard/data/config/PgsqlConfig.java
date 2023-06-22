package com.rsgisai.geohazard.data.config;

import org.apache.ibatis.session.Configuration;
import org.apache.ibatis.session.SqlSessionFactory;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.SpringBootConfiguration;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.core.io.support.PathMatchingResourcePatternResolver;
import org.springframework.core.io.support.ResourcePatternResolver;

import javax.sql.DataSource;

@SpringBootConfiguration
@MapperScan(basePackages = "com.rsgisai.geohazard.data.dao.pgsql",
        sqlSessionFactoryRef = "pgsqlSessionFactory")
public class PgsqlConfig {

    @Bean
    public SqlSessionFactory pgsqlSessionFactory(
            @Qualifier("pgsqlDataSource") DataSource pgsqlDataSource
    ) throws Exception {
        SqlSessionFactoryBean sqlSessionFactoryBean = new SqlSessionFactoryBean();
        // 数据源配置
        sqlSessionFactoryBean.setDataSource(pgsqlDataSource);

        //添加XML目录
        ResourcePatternResolver resolver = new PathMatchingResourcePatternResolver();
        try {
            sqlSessionFactoryBean.setMapperLocations(resolver.getResources("classpath:/pgsqlMapper/*.xml"));
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }

        // MyBatis配置
        Configuration configuration=new Configuration();
        configuration.setMapUnderscoreToCamelCase(true);
        sqlSessionFactoryBean.setConfiguration(configuration);


        return sqlSessionFactoryBean.getObject();
    }

}
