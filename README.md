# 工程简介
本项目是 地质灾害隐患风险遥感评估分系统 的服务端项目，各模块描述如下：
1. auth: 认证授权模块
2. eureka-server: 微服务注册中心  port：20222
3. gateway: API网关                port：20223    
4. geohazard-business: 四个业务模块
      - geohazard-chain    port:20231
      - influence-scope-mechanics   port:20232
      - influence-scope-statistic      port : 20233
      - risk-level     port:20234
      - sub-system 20235
5. geohazard-computation: 地质灾害计算服务模块  
   5.1 geohazard-data: 地质灾害数据管理模块  port :20242
   5.2 geospatial-computation: 地质灾害地理算法执行模块   port :20241
6. gis-tools: 一些处理地理数据的工具
7. system-common: 各模块公用的实体类等


# 延伸阅读

