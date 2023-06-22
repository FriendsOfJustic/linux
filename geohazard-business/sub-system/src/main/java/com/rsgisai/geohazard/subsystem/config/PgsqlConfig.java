package com.rsgisai.geohazard.subsystem.config;

import org.apache.ibatis.session.Configuration;
import org.apache.ibatis.session.SqlSessionFactory;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.SpringBootConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.core.io.support.PathMatchingResourcePatternResolver;
import org.springframework.core.io.support.ResourcePatternResolver;

import javax.sql.DataSource;

@SpringBootConfiguration
@MapperScan(basePackages = "com.rsgisai.geohazard.subsystem.dao.pgsql",
        sqlSessionFactoryRef = "pgsqlSessionFactory")
public class PgsqlConfig {

    @Bean
    public SqlSessionFactory pgsqlSessionFactory(@Qualifier("pgsqlDataSource") DataSource oracleDataSource) throws Exception {
        SqlSessionFactoryBean bean = new SqlSessionFactoryBean();
        bean.setDataSource(oracleDataSource);

        //添加XML目录
        ResourcePatternResolver resolver = new PathMatchingResourcePatternResolver();
        try {
            bean.setMapperLocations(resolver.getResources("classpath:/pgsqlMapper/*.xml"));


            // MyBatis配置
            Configuration configuration=new Configuration();
            configuration.setMapUnderscoreToCamelCase(true);
            bean.setConfiguration(configuration);

            return bean.getObject();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }

}
