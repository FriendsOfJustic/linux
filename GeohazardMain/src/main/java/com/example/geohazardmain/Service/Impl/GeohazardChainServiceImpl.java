package com.example.geohazardmain.Service.Impl;


import com.example.geohazardmain.Service.GeohazardChainService;
import com.example.geohazardmain.client.GeohazardChainClient;
import com.example.sys.transfer.NumOfReclass;
import org.postgresql.util.PSQLException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.IOException;


@Service
public class GeohazardChainServiceImpl implements GeohazardChainService {

    @Autowired
    GeohazardChainClient geohazardChainClient;

    @Override
    public void PollingLogic() throws IOException, PSQLException {
        NumOfReclass tmp=new NumOfReclass(2,3,4,5,6,7,8);
        System.out.println("开始发送请求");
        geohazardChainClient.SusAlgorithm(tmp);
        geohazardChainClient.watervolumeCalculate(90000.000);
        System.out.println("结束");
    }
}