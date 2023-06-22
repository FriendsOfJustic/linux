package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.service.impl.CompositionOperatorServiceSyncImpl;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.computation.geospatial.service.impl.CompositionOperatorServiceAsyncImpl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;

@SpringBootTest
class AspectReclassifyCompositionTest {

    @Autowired// 单元测试里面不可以使用构造函数引入依赖，否则报错
    CompositionOperatorServiceSyncImpl compositionOperatorService;

    String dsl =
            // @formatter:off
            "Parameters: Integer  numberClasses\n" +
            "aspect = GH_Aspect()\n" +
            "slope_reclassify = DZ_AspectReclassify(aspect, numberClasses)\n" +
            "Output: slope_reclassify\n";
            // @formatter:on

    @Test
    void parse() throws IOException {
        CompositionOperator compositionOperator = CompositionOperatorService.parse(dsl);
        System.out.println("compositionOperator = " + compositionOperator);
        System.out.println(int.class);
    }

    @Test
    void add() {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_AspectReclassify";
        compositionOperator.dsl = dsl;
        compositionOperator.userId = 8L;
        compositionOperatorService.add(compositionOperator);
    }

    @Test
    void update() {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_AspectReclassify";
        compositionOperator.dsl = dsl;
        compositionOperator.userId = 5L;
        compositionOperatorService.update(compositionOperator);
    }

    @Test
    void operate() throws IOException, InvocationTargetException, IllegalAccessException {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "GH_AspectReclassify";
        compositionOperator.workingAreaId = 1L;
        compositionOperator.userId = 9L;
        compositionOperator.arguments.put("numberClasses", 9);
        long operate = compositionOperatorService.operate(compositionOperator);
        System.out.println("operate = " + operate);
    }
}