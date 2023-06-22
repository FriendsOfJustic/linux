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
class CompositionOperatorServiceTest {

    @Autowired// 单元测试里面不可以使用构造函数引入依赖，否则报错
    CompositionOperatorServiceSyncImpl compositionOperatorService;

    String dsl =
            // @formatter:off
            "Parameters: Integer  numberClasses\n" +
            "dem = DZ_OriginRaster(\"dem\")\n" +
            "slope = DZ_Slope(dem)\n" +
            "slope_reclassify = DZ_EqualIntervalReclassify(slope, numberClasses)\n" +
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
        compositionOperator.name = "slope_reclassify";
        compositionOperator.dsl = dsl;
        compositionOperator.userId = 8L;
        compositionOperatorService.add(compositionOperator);
    }

    @Test
    void update() {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "slope_reclassify";
        compositionOperator.dsl = dsl;
        compositionOperator.userId = 9L;
        compositionOperatorService.update(compositionOperator);
    }

    @Test
    void operate() throws IOException, InvocationTargetException, IllegalAccessException {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "slope_reclassify";
        compositionOperator.dsl = dsl;
        compositionOperator.workingAreaId = 9L;
        compositionOperator.userId = 9L;
        compositionOperator.arguments.put("numberClasses", 8);
        compositionOperatorService.operate(compositionOperator);
    }
}