package com.rsgisai.geohazard.subsystem.controller;

import com.rsgisai.geohazard.subsystem.service.PotentialInfluenceService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.PotentialInfluence;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @author tfh, created at 2023-04-24 10:19 PM
 */
@RestController
@RequestMapping("/potential-influence")
public class PotentialInfluenceController {

    @Autowired
    PotentialInfluenceService potentialInfluenceService;

    /*@GetMapping
    R<List<PotentialInfluence>> select(PotentialInfluence potentialInfluence) {
        return R.ok(potentialInfluenceService.select(potentialInfluence));
    }*/


    @GetMapping
    public R<List<PotentialInfluence>> list(PotentialInfluence potentialInfluence){
        return R.ok(potentialInfluenceService.queryBy(potentialInfluence));
    }




}
