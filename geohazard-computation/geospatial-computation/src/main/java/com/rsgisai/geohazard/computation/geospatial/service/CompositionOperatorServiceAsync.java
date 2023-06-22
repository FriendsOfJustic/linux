package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import org.springframework.scheduling.annotation.Async;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

/**
 * @author tfh, created at 2023-04-07 10:51 PM
 */
public interface CompositionOperatorServiceAsync {
    Map<String, Class<?>> typeMap = new HashMap<String, Class<?>>() {{
        put("Integer", Integer.class);
        put("String", String.class);
    }};
    CompositionOperator query(CompositionOperator compositionOperator);

    boolean verifyDsl(String dsl);

    void add(CompositionOperator compositionOperator);

    int update(CompositionOperator compositionOperator);

//    GeohazardComputationJob submit(CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException, ExecutionException, InterruptedException;

    @Async
    CompletableFuture<Long> execute(CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException, ExecutionException, InterruptedException;
}
