package com.example;

import com.baomidou.mybatisplus.generator.FastAutoGenerator;
import com.baomidou.mybatisplus.generator.config.OutputFile;
import com.baomidou.mybatisplus.generator.engine.FreemarkerTemplateEngine;

import java.util.Collections;

public class codegenerator {
    public static void main(String[] args) {
        String url="jdbc:postgresql://122.112.250.145:15432/geohazard?currentSchema=public";
        String username="geohazard";
        String passwrd="cumtb_2023_rerssil";
        String modulename="sys";
        String mapperLocation="Z:\\git\\spring\\geohazard-risk-server\\geohazard-business\\geohazard-chain\\src\\main\\resources\\"+modulename;
        String tables="dongchuanlandslide";
        FastAutoGenerator.create(url, username, passwrd)
                .globalConfig(builder -> {
                    builder.author("sht") // 设置作者
                            //.enableSwagger() // 开启 swagger 模式
                            //.fileOverride() // 覆盖已生成文件
                            .outputDir("Z:\\git\\spring\\geohazard-risk-server\\geohazard-business\\geohazard-chain\\src\\main\\java"); // 指定输出目录
                })
                .packageConfig(builder -> {
                    builder.parent("com.example") // 设置父包名
                            .moduleName(modulename) // 设置父包模块名
                            .pathInfo(Collections.singletonMap(OutputFile.xml, mapperLocation)); // 设置mapperXml生成路径
                })
                .strategyConfig(builder -> {
                    builder.addInclude(tables) ;// 设置需要生成的表名
                            //.addTablePrefix("x_"); // 设置过滤表前缀
                })
                .templateEngine(new FreemarkerTemplateEngine()) // 使用Freemarker引擎模板，默认的是Velocity引擎模板
                .execute();
    }
}
