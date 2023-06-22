package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.service.impl.CompositionOperatorServiceSyncImpl;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.InvocationTargetException;

@SpringBootTest
class SusceptibilityCompositionTest {

    @Autowired// 单元测试里面不可以使用构造函数引入依赖，否则报错
    CompositionOperatorServiceSyncImpl compositionOperatorService;

    String dsl = "";

    public SusceptibilityCompositionTest() {
        InputStream inputStream = getClass().getClassLoader().getResourceAsStream("compositionOperator/GH_Susceptibility.GHDSL");
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        reader.lines().forEach(s -> dsl += s + '\n');
    }

    @Test
    void empty() {
        System.out.println("dsl = " + dsl);
        System.out.println("OK!");
    }

    @Test
    void parse() throws IOException {
        CompositionOperator compositionOperator = CompositionOperatorService.parse(dsl);
        System.out.println("compositionOperator = " + compositionOperator);
        System.out.println(int.class);
    }

    @Test
    void add() {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_Susceptibility";
        compositionOperator.dsl = dsl;
        compositionOperator.userId = 8L;
        compositionOperatorService.add(compositionOperator);
    }

    @Test
    void update() {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_Susceptibility";
        compositionOperator.dsl = dsl;
        compositionOperator.userId = 5L;
        compositionOperatorService.update(compositionOperator);
    }

    @Test
    void operate() throws IOException, InvocationTargetException, IllegalAccessException {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_Susceptibility";
        compositionOperator.workingAreaId = 1L;
        compositionOperator.userId = 9L;
        compositionOperator.arguments.put("demNumberClasses", 6);
        compositionOperator.arguments.put("slopeNumberClasses", 6);
        compositionOperator.arguments.put("aspectNumberClasses", 6);
        compositionOperator.arguments.put("outNumberClasses", 4);
        long operate = compositionOperatorService.operate(compositionOperator);
        System.out.println("operate = " + operate);
    }
}