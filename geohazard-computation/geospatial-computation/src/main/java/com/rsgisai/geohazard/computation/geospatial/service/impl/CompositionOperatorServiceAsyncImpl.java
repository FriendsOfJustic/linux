package com.rsgisai.geohazard.computation.geospatial.service.impl;

import com.rsgisai.geohazard.computation.geospatial.client.ResultRasterClient;
import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.CompositionOperatorDao;
import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.GeohazardComputationJobDao;
import com.rsgisai.geohazard.computation.geospatial.exception.GhdslFormatException;
import com.rsgisai.geohazard.computation.geospatial.exception.GhdslOperateException;
import com.rsgisai.geohazard.computation.geospatial.service.CompositionOperatorServiceAsync;
import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.computation.geospatial.entity.QueryMeta;
import com.rsgisai.geohazard.computation.geospatial.service.BuiltInOperatorService;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import com.rsgisai.geohazard.system.common.ResultRaster;
import com.rsgisai.geohazard.system.common.util.DevelopmentUtil;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

@Service
public class CompositionOperatorServiceAsyncImpl implements CompositionOperatorServiceAsync {

    final GeohazardComputationJobDao geohazardComputationJobDao;

    private final CompositionOperatorDao compositionOperatorDao;
    private final BuiltInOperatorServiceImpl builtInOperatorService;
    private final Map<String, Method> builtInOperators;
    private final ResultRasterClient resultRasterClient;

    @Override
    public CompositionOperator query(CompositionOperator compositionOperator) {
        return compositionOperatorDao.selectOne(compositionOperator);
    }

    public CompositionOperatorServiceAsyncImpl(
            @Qualifier("compositionOperatorDao") CompositionOperatorDao compositionOperatorDao,
            BuiltInOperatorServiceImpl builtInOperatorService,
            GeohazardComputationJobDao geohazardComputationJobDao,
            ResultRasterClient resultRasterClient) {
        this.compositionOperatorDao = compositionOperatorDao;
        this.builtInOperatorService = builtInOperatorService;

        HashMap<String, Method> builtInOperatorsMap = new HashMap<>();
        Method[] declaredMethods = BuiltInOperatorService.class.getDeclaredMethods();
        for (Method declaredMethod : declaredMethods) {
            builtInOperatorsMap.put(declaredMethod.getName(), declaredMethod);
        }
        this.builtInOperators = builtInOperatorsMap;
        this.geohazardComputationJobDao = geohazardComputationJobDao;
        this.resultRasterClient = resultRasterClient;
    }

    @Override
    public boolean verifyDsl(String dsl) {
        throw DevelopmentUtil.tobeImplemented("com.rsgisai.geohazard.computation.geospatial.service.impl.CompositionOperatorServiceAsyncImpl.verifyDsl");
//        return true;
    }

    @Override
    public void add(CompositionOperator compositionOperator) {
        if (compositionOperatorDao.exist(compositionOperator))
            throw new RuntimeException("add new composition operator failed: " +
                    "operator with name '" + compositionOperator.name + "' already exist.");
        compositionOperatorDao.insert(compositionOperator);
    }

    @Override
    public int update(CompositionOperator compositionOperator) {
        if (!compositionOperatorDao.exist(compositionOperator))
            throw new RuntimeException("update composition operator failed: " +
                    "operator with name '" + compositionOperator.name + "' dose not exist.");
        return compositionOperatorDao.update(compositionOperator);
    }


    private long doFunctionCall(String functionCall, HashMap<String, Object> variables, QueryMeta queryMeta) throws InvocationTargetException, IllegalAccessException, IOException, ExecutionException, InterruptedException {
        String operatorName = functionCall.substring(0, functionCall.indexOf('(')).trim();

        // parse function call arguments
        String[] rawArgs = functionCall.substring(
                functionCall.indexOf('(') + 1,
                functionCall.lastIndexOf(')')
        ).split(",");
        for (int i = 0; i < rawArgs.length; i++)
            rawArgs[i] = rawArgs[i].trim();

        Method method;
        // for built-in method
        if (builtInOperators.containsKey(operatorName)) {
            method = builtInOperators.get(operatorName);
            // prepare args
            Object[] args = prepareArgs(rawArgs, method.getParameterTypes(), variables, queryMeta);
            // built-in method invoke directly
            return (long) method.invoke(builtInOperatorService, args);

        } else {// for other composition operator
            // prepare arguments
            CompositionOperator compositionOperator = new CompositionOperator();
            compositionOperator.name = operatorName;
            compositionOperator.workingAreaId = queryMeta.workingAreaId;
            compositionOperator.userId = queryMeta.userId;
            compositionOperator.arguments = new TreeMap<>(variables);


            // prepare new job to execute recursively
            GeohazardComputationJob geohazardComputationJob = new GeohazardComputationJob();
            geohazardComputationJob.name = compositionOperator.name;
            geohazardComputationJob.status = "ready";
            geohazardComputationJob.currentLine = 0;
            geohazardComputationJob.createBy = compositionOperator.userId;
            geohazardComputationJob.modifyBy = compositionOperator.userId;

            if (geohazardComputationJobDao.insert(geohazardComputationJob) > 0) {
                // execute asynchronously
                compositionOperator.jobId = geohazardComputationJob.id;
                // call other GHDSL
                return execute(compositionOperator).get();
            } else {
                throw new RuntimeException("failed to add new Job!");
            }
        }
    }


    private Object[] prepareArgs(String[] rawArgs, Class<?>[] parameterTypes, HashMap<String, Object> variables, QueryMeta queryMeta) {
        ArrayList<Object> objects = new ArrayList<Object>();
        objects.add(queryMeta);
        for (int i = 0; i < parameterTypes.length - 1; i++) {// 第一个是 queryMeta 已经放进去了
            Class<?> parameterType = parameterTypes[i + 1];
            String rawArg = rawArgs[i];
            if (parameterType.equals(String.class)) {
                if (variables.containsKey(rawArg)) objects.add(variables.get(rawArg));
                else
                    objects.add(rawArg.substring(1, rawArg.length() - 1));
            } else if (parameterType.equals(Integer.class)) {
                if (variables.containsKey(rawArg)) objects.add(variables.get(rawArg));
                else
                    objects.add(Integer.valueOf(rawArg));
            } else if (parameterType.equals(long.class)) {
                objects.add(variables.get(rawArg));
            } else if (parameterType.equals(Object[].class)) {
                objects.add(prepareVariableArgs(i, rawArgs, variables));
                break;
            } else if (parameterType.equals(long[].class)){
                throw new RuntimeException("unsupported type: " + parameterType.getName());
            } else {
                throw new RuntimeException("unsupported type: " + parameterType.getName());
            }
        }
        return objects.toArray();
    }

    private Object[] prepareVariableArgs(int i, String[] rawArgs, HashMap<String, Object> variables) {
        ArrayList<Object> objects = new ArrayList<>();
        for (; i < rawArgs.length; i++) {
            String rawArg = rawArgs[i].trim();
            if (variables.containsKey(rawArg))
                objects.add(variables.get(rawArg));
            else if (rawArg.startsWith("\"") && rawArg.endsWith("\""))
                objects.add(rawArg.substring(1, rawArg.length() - 1));
            else
                objects.add(rawArg);
        }
        return objects.toArray();
    }

//    @Override
//    public GeohazardComputationJob submit(CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException, ExecutionException, InterruptedException {
//        GeohazardComputationJob geohazardComputationJob = new GeohazardComputationJob();
//        geohazardComputationJob.name = compositionOperator.name;
//        geohazardComputationJob.status = "ready";
//        geohazardComputationJob.currentLine = 0;
//        geohazardComputationJob.createBy = compositionOperator.userId;
//        geohazardComputationJob.modifyBy = compositionOperator.userId;
//
//        if (geohazardComputationJobDao.insert(geohazardComputationJob) > 0) {
//
//            CompletableFuture<Long> execute = execute(compositionOperator);
//
//            return geohazardComputationJob;
//        } else {
//            throw new RuntimeException("submit failed");
//        }
//    }

    @Override
    @Async
    public CompletableFuture<Long> execute(CompositionOperator compositionOperator) throws IOException, InvocationTargetException, IllegalAccessException, ExecutionException, InterruptedException {
        try {
            long jobId = compositionOperator.jobId;
            QueryMeta queryMeta = new QueryMeta(compositionOperator.workingAreaId, compositionOperator.userId);
            Map<String, Object> arguments = compositionOperator.arguments;
            compositionOperator = compositionOperatorDao.selectOne(compositionOperator);
            String dsl = compositionOperator.dsl;


            BufferedReader bufferedReader = new BufferedReader(new StringReader(dsl));

            int currentLine = 0;
            // prepare arguments
            String line = bufferedReader.readLine();
            currentLine++;
            String[] parameters = line.substring(line.indexOf(':') + 1).split(",");
            // argument check
            for (String param : parameters) {
                String[] s = param.trim().split("\\s+");// split by any number of spaces
                String typeName = s[0].trim();
                if ("None".equalsIgnoreCase(typeName)) break;// 不需要参数
                String parameterName = s[1].trim();
                if (!typeMap.containsKey(typeName)) throw new GhdslFormatException("unsupported type: " + typeName);

                if (!arguments.containsKey(parameterName))
                    throw new GhdslOperateException("operate dsl failed: missing argument '" + parameterName + "'");
                Object argument = arguments.get(parameterName);
                Class<?> parameterType = typeMap.get(typeName);
                if (!parameterType.equals(argument.getClass()))
                    throw new GhdslOperateException(String.format("operate dsl failed: argument type mismatch, require '%s', provided '%s'.",
                            parameterType.getName(), argument.getClass().getName()));
            }

            HashMap<String, Object> variables = new HashMap<>(arguments);
            // operate
            while ((line = bufferedReader.readLine()) != null) {
                currentLine++;
                line = line.trim();
                if (line.length() == 0) continue;// 跳过空行
                if (line.startsWith("--")) continue;// 跳过注释
                if (line.startsWith("Output:")) {
                    String s = line.split("\\s+")[1].trim();
                    if ("None".equalsIgnoreCase(s)) return CompletableFuture.completedFuture(0L);

                    long result = (long) variables.get(s);
                    return CompletableFuture.completedFuture(result);
                } else if (line.startsWith("Save:")) {
                    String feature = line.split("\\s+")[1].trim();
                    long resultRasterId = (long) variables.get(feature);
                    // save
                    long savedRasterId = builtInOperatorService.SaveRaster(
                            queryMeta, resultRasterId, feature, compositionOperator.name,
                            new TreeMap<>(arguments)
                    );
                    geohazardComputationJobDao.updateSavedResult(jobId, savedRasterId);

                    // publish
                    ResultRaster resultRaster = new ResultRaster();
                    resultRaster.feature = feature;
                    resultRaster.workingAreaId = queryMeta.workingAreaId;
                    resultRaster.arguments = new TreeMap<>(arguments);
                    resultRasterClient.publish(resultRaster);

                } else if (line.contains("=")) {
                    String[] split = line.split("=");
                    String variableName = split[0].trim();
                    String functionCallString = split[1].trim();
                    geohazardComputationJobDao.updateCurrentLine(jobId, currentLine);
                    long resultId = this.doFunctionCall(functionCallString, variables, queryMeta);
                    variables.put(variableName, resultId);
                } else {
                    this.doFunctionCall(line, variables, queryMeta);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CompletableFuture.completedFuture(-1L);
    }
}