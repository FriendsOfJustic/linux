package com.example.sys.service;

import org.postgresql.util.PSQLException;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.List;

public interface SusAlgorithmService {

    public Integer SusAlgorithm(Integer x[]) throws IOException, PSQLException;

    public String ReDefine(Integer num, List<Double> info);
    public String Reclass(Integer num,Integer id);
}
