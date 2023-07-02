package com.example.geohazardmain.client;


import com.example.geohazardmain.Transfer.R;
import com.example.geohazardmain.config.MyFeignConfig;
import com.example.sys.transfer.NumOfReclass;
import org.postgresql.util.PSQLException;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;


//灾害链后端的整合逻辑

@FeignClient(name = "geohazard-chain",configuration = MyFeignConfig.class)// 注册在Eureka的里面的服务的名称  & 也可以写成绝对的URL
public interface GeohazardChainClient {

    @GetMapping("/geohazard-chain/sys3/watervolume")
    public R<String> watervolumeCalculate(@RequestParam("waterlevel") Double waterlevel) throws IOException;


    @PostMapping("/geohazard-chain/sys1/algorithem")
    public R<String> SusAlgorithm(@RequestBody NumOfReclass s) throws PSQLException, IOException;


}
