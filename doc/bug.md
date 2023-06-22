# 运行时出现字符集问题，无法启动
## 原因
新的项目还未配置IDE的字符集
## 解决方案
设置IDE的字符为UTF-8

# 容器里找不到 pgsql 的DAO对象
## 解决方案
在 PgsqlConfig 修改 basePackages
```java
@MapperScan(basePackages = "com.rsgisai.geohazard.subsystem.dao.pgsql",
        sqlSessionFactoryRef = "pgsqlSessionFactory")
```

# application.yml 中 MyBatis的配置无效
## 原因
配置了多数据源
## 解决方案
### 方案1（使用）
```java
sqlSessionFactoryBean.setConfiguration(configuration);
```
### 方案2
需要在 MySqlConfig/PgsqlConfig里面对 MyBatis进行配置

