package com.example.sys.controller;


import com.example.sys.service.FloodInfluenceAreaService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.math.BigInteger;

@RestController
@RequestMapping("/sys4")
public class FloodInfluenceAreaController {


    @Autowired
    FloodInfluenceAreaService floodInfluenceAreaService;

    //输入参数 坐标x、y 高程h@RequestParam("x") Double x,@RequestParam("y") Double y,@RequestParam("H") Double h
    @GetMapping("algorithm")
    public R<String> functon() throws IOException {
        floodInfluenceAreaService.AlgorithmCall(1200,900,1700,new BigInteger("624882232324500"));
        return R.ok("hello");
    }

}



