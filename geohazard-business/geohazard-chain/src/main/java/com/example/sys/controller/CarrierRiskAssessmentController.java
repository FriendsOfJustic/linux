package com.example.sys.controller;


import com.example.sys.entity.CarrierLossCaculatePerFloodArea;
import com.example.sys.mapper.CarrierRiskAssessmentMapper;
import com.example.sys.service.CarrierRiskAssessmentService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/sys5")
public class CarrierRiskAssessmentController {

    @Autowired
    private CarrierRiskAssessmentMapper carrierRiskAssessmentMapper;


    @Autowired
    private CarrierRiskAssessmentService carrierRiskAssessmentService;

    @GetMapping("/Algorithmn")
    public R< List<CarrierLossCaculatePerFloodArea>> CarrierAssessmentAlgorithmn()
    {
        List<CarrierLossCaculatePerFloodArea> result=carrierRiskAssessmentService.CarrierRiskAssessmentAlgorithmn();


        return R.ok(result);
    }

}
