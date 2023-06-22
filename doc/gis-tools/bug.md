# 如果发现找不到 org.locationtech 相关的依赖

## 现象

ShapeFiles 类的依赖无法解决

## 原因

gis-tools 模块依赖于 geotools 相关的依赖，但是在没有处理完深层依赖（geotools 依赖于 locationtech），加可以编译成功（why？）
## 处理办法
尝试重新编译、打包；尝试在IDEA的 Maven panel 点击 download source and documentation。等等，反正就是得让 locationtech 相关的依赖被下载下来，才能解决问题。
