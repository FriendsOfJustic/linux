package com.example.sys.controller;

import com.example.sys.mapper.SusAlgorithmMapper;
import com.example.sys.service.SusAlgorithmService;
import com.example.sys.transfer.NumOfReclass;
import com.rsgisai.geohazard.system.common.R;
import org.postgresql.util.PSQLException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.List;

@RestController
@RequestMapping("/sys1")
public class SusAlgorithmController {

    @Autowired
    private SusAlgorithmMapper susAlgorithmMapper;


    @Autowired
    private SusAlgorithmService service;

    @PostMapping("/algorithem")
    private R<String> SusAlgorithm(@RequestBody NumOfReclass s) throws PSQLException, IOException {
        Integer[] x=new Integer[7];
        x[0]=s.getNumDem();
        System.out.println(x[0]);
        x[1]=s.getNumSlop();
        System.out.println(x[1]);
        x[2]=s.getNumAspect();
        System.out.println(x[2]);
        x[3]=s.getNumCurvature();
        System.out.println(x[3]);
        x[4]=s.getNumWater();
        System.out.println(x[4]);
        x[5]=s.getNumRainFall();
        System.out.println(x[5]);
        x[6]=s.getNumRock();
        System.out.println(x[6]);


        service.SusAlgorithm(x);


//        List<Double> x=susAlgorithmMapper.selectRiskPoint_x();
//
//        for (Double e: x
//             ) {
//            System.out.println(e);
//        }
//
//
//        List<Double> y=susAlgorithmMapper.selectRiskPoint_y();
//
//        for (Double e: y
//        ) {
//            System.out.println(e);
//        }

        return R.ok("pieceOfshit");

    }
}
