package com.rsgisai.geohazard.data.controller;


import com.rsgisai.geohazard.data.vo.TransType_qg;
import com.rsgisai.geohazard.data.vo.TransType_yjq;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;


//与前端数据管理界面的后端接口
@RestController
@RequestMapping("/management")
public class ResearchAreaDataController {

    //研究区的后端接口
    @PostMapping("/yjq")
    public R<List<TransType_yjq>> yjq_interface()
    {
        //test数据

        List<TransType_yjq> test=new ArrayList<>();
        test.add(new TransType_yjq("石海涛",2023,4,"测试","北京","矿大"));
        test.add(new TransType_yjq("胡靖宇",2023,4,"测试","北京","矿大"));

        return R.ok(test);
    }



    //全国区域的后端接口
    @GetMapping("/qg")
    public List<TransType_qg>  qg_interface()
    {
        //不做测试
        return null;
    }

}
