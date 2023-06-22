package com.rsgisai.geohazard.statistic.config;

import org.apache.ibatis.session.SqlSessionFactory;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.mybatis.spring.SqlSessionTemplate;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.SpringBootConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Primary;
import org.springframework.core.io.support.PathMatchingResourcePatternResolver;
import org.springframework.core.io.support.ResourcePatternResolver;

import javax.sql.DataSource;

@SpringBootConfiguration
@MapperScan(basePackages = "com.rsgisai.geohazard.statistic.dao.mysql", sqlSessionFactoryRef = "mysqlSessionFactory")
public class MySqlConfig {

    @Autowired
    @Qualifier("mysqlDataSource")
    private DataSource mySqlDataSource;

    @Bean
    @Primary
    public SqlSessionFactory mysqlSessionFactory() {
        SqlSessionFactoryBean factoryBean = new SqlSessionFactoryBean();
        factoryBean.setDataSource(mySqlDataSource);


//	    factoryBean.setPlugins(mybatisPlusConfig.paginationInterceptor());
        /*SqlSessionFactoryBean bean = new SqlSessionFactoryBean();
        bean.setDataSource(mySqlDataSource);
        bean.setPlugins(new Interceptor[]{mybatisPlusConfig.paginationInterceptor()});*/

        //添加XML目录
        ResourcePatternResolver resolver = new PathMatchingResourcePatternResolver();
        try {
            factoryBean.setMapperLocations(resolver.getResources("classpath:/mysqlMapper/*.xml"));
            return factoryBean.getObject();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }

    @Bean
    @Primary
    public SqlSessionTemplate mysqlSqlSessionTemplate() {
        return new SqlSessionTemplate(mysqlSessionFactory());
    }

}
