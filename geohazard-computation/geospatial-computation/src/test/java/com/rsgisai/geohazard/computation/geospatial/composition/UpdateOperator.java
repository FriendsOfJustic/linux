package com.rsgisai.geohazard.computation.geospatial.composition;

import com.rsgisai.geohazard.computation.geospatial.service.CompositionOperatorService;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import org.apache.commons.io.FileUtils;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.*;
import java.net.URL;
import java.nio.charset.StandardCharsets;

/**
 * @author tfh, created at 2023-04-13 11:06 PM
 */
@SpringBootTest
public class UpdateOperator {

    @Autowired
    CompositionOperatorService compositionOperatorService;

    @Test
    void GH_Susceptibility() throws IOException {
        String alg_name = "GH_Susceptibility";
        URL resource = this.getClass().getClassLoader()
                .getResource("compositionOperator/" + alg_name + ".GHDSL");

        String dsl = FileUtils.readFileToString(
                new File(resource.getFile()), StandardCharsets.UTF_8);
        System.out.println(dsl);

        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = alg_name;
        compositionOperator.dsl = dsl;

        compositionOperator.userId = 1L;// modify_by
        compositionOperatorService.update(compositionOperator);
    }
    @Test
    void GH_Probability() throws IOException {
        String alg_name = "GH_Probability";
        URL resource = this.getClass().getClassLoader()
                .getResource("compositionOperator/" + alg_name + ".GHDSL");

        String dsl = FileUtils.readFileToString(
                new File(resource.getFile()), StandardCharsets.UTF_8);
        System.out.println(dsl);

        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = alg_name;
        compositionOperator.dsl = dsl;

        compositionOperator.userId = 1L;// modify_by
        compositionOperatorService.update(compositionOperator);
    }
    @Test
    void GH_ProbabilityEarthquake() throws IOException {
        String alg_name = "GH_ProbabilityEarthquake";
        URL resource = this.getClass().getClassLoader()
                .getResource("compositionOperator/" + alg_name + ".GHDSL");

        String dsl = FileUtils.readFileToString(
                new File(resource.getFile()), StandardCharsets.UTF_8);
        System.out.println(dsl);

        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = alg_name;
        compositionOperator.dsl = dsl;

        compositionOperator.userId = 1L;// modify_by
        compositionOperatorService.update(compositionOperator);
    }
}
