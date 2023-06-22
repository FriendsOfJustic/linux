package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.system.common.entity.PotentialInfluence;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
public class PotentialInfluenceTest {
    @Autowired
    PotentialInfluenceService potentialInfluenceService;

    @Test
    void select(){

        PotentialInfluence p = new PotentialInfluence();
        p.setWorkingAreaId(1L);
        p.setYear(2022);
        List<PotentialInfluence> potentialInfluences = potentialInfluenceService.queryBy(p);
        System.out.println("-------输出-------");
        potentialInfluences.forEach(System.out::println);



    }
}
