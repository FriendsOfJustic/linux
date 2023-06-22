package com.rsgisai.geohazard.system.common;

import lombok.Data;

import java.util.*;

@Data
public class CompositionOperator {
    public Long id;

    // original
    public String name;
    public String dsl;

    // for invocation
    /**
     * JSON 的 number 会被反序列化为 Integer
     * 实参叫 Argument，形参是 Parameter
     */
    public SortedMap<String, Object> arguments = new TreeMap<>();

    // processing operator
    public Long jobId;

    // meta
    public Long workingAreaId;
    public Long userId;

    // parsed
    public Map<String, Class<?>> parameters = new HashMap<>();
    public Map<String, Collection<?>> directedAcyclicGraph = new HashMap<>();
    public Set<String> targets = new HashSet<>();
}
