package com.rsgisai.geohazard.data.config;

import org.apache.ibatis.session.Configuration;
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
@MapperScan(basePackages = "com.rsgisai.geohazard.data.dao.mysql",
        sqlSessionFactoryRef = "mysqlSessionFactory")
public class MySqlConfig {

    @Autowired
    @Qualifier("mysqlDataSource")
    private DataSource mySqlDataSource;

    @Bean
    @Primary
    public SqlSessionFactory mysqlSessionFactory(
    ) {
        SqlSessionFactoryBean sqlSessionFactoryBean = new SqlSessionFactoryBean();
        sqlSessionFactoryBean.setDataSource(mySqlDataSource);


//	    factoryBean.setPlugins(mybatisPlusConfig.paginationInterceptor());
        /*SqlSessionFactoryBean bean = new SqlSessionFactoryBean();
        bean.setDataSource(mySqlDataSource);
        bean.setPlugins(new Interceptor[]{mybatisPlusConfig.paginationInterceptor()});*/

        //添加XML目录
        ResourcePatternResolver resolver = new PathMatchingResourcePatternResolver();
        try {
            sqlSessionFactoryBean.setMapperLocations(resolver.getResources("classpath:/mysqlMapper/*.xml"));


            // MyBatis配置
            Configuration configuration=new Configuration();
            // 驼峰命名法
            configuration.setMapUnderscoreToCamelCase(true);
            sqlSessionFactoryBean.setConfiguration(configuration);

            return sqlSessionFactoryBean.getObject();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }

    }

    @Bean
    @Primary
    public SqlSessionTemplate mysqlSqlSessionTemplate(
    ) {
        return new SqlSessionTemplate(mysqlSessionFactory());
    }

}
