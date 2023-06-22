package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.computation.geospatial.exception.GhdslFormatException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

public interface CompositionOperatorService {
    Map<String, Class<?>> typeMap = new HashMap<String, Class<?>>() {{
        put("Integer", Integer.class);
        put("String", String.class);
    }};

    static CompositionOperator parse(String dsl) throws IOException {
        CompositionOperator compositionOperator = new CompositionOperator();

        BufferedReader bufferedReader = new BufferedReader(new StringReader(dsl));
        // step 1: parse arguments requirement
        String line = bufferedReader.readLine();
        String[] args = line.substring(line.indexOf(':') + 1).split(",");
        for (String arg : args) {
            String[] s = arg.trim().split("\\s+");// split by any number of spaces
            String type = s[0].trim();
            if (!typeMap.containsKey(type)) throw new GhdslFormatException("unsupported type: " + type);
            String argName = s[1].trim();
            compositionOperator.parameters.put(argName, typeMap.get(type));
        }

        // step 2: ?
        while ((line = bufferedReader.readLine()) != null) {// loop through remaining lines

        }

        return compositionOperator;
    }

    boolean verifyDsl(String dsl);

    void add(CompositionOperator compositionOperator);

    /**
     * update composition operator has the same name
     */
    int update(CompositionOperator compositionOperator);

    /**
     * 根据请求参数，执行GDSL，并返回中间结果ID
     * @param compositionOperator
     * @return
     * @throws IOException
     */
    long operate(CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException;

    CompositionOperator query(CompositionOperator compositionOperator);
}
