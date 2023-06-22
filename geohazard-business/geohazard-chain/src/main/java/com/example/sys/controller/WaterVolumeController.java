package com.example.sys.controller;


import com.example.sys.service.IWaterVolumeService;
import com.example.sys.vo.resultType;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.math.BigDecimal;

@RestController
@RequestMapping("/sys3")
public class WaterVolumeController {

    @Autowired
    IWaterVolumeService iWaterVolumeService;


    //返回的体积单位是 立方千米
    @GetMapping("/watervolume")
    public R<String> watervolumeCalculate(@RequestParam("waterlevel") Double waterlevel) throws IOException {
        System.out.println(waterlevel);
        BigDecimal ret=iWaterVolumeService.WaterVolumeAlgorithm(waterlevel);
        String result=ret.toString();
        return R.ok(result);
    }
}
