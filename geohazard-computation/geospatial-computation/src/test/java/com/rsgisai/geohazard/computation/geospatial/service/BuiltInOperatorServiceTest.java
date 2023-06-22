package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.entity.QueryMeta;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-03-12 2:19 PM
 */
@SpringBootTest
class BuiltInOperatorServiceTest {

    @Autowired
    BuiltInOperatorService builtInOperatorService;

    @Test
    void DZ_OriginRaster() {
        QueryMeta queryMeta = new QueryMeta(1L, 2L);
        long dem = builtInOperatorService.DZ_OriginRaster(queryMeta, "dem");
        System.out.println("dem = " + dem);
    }

    @Test
    void DZ_Weight() {
        long[] entropy = {
                (long) (0.871418404 * 1000000),
                (long) (0.901544101 * 1000000),
                (long) (0.815017738 * 1000000),
        };
        QueryMeta queryMeta = new QueryMeta(1L, 2L);
        long l = builtInOperatorService.DZ_Weight(queryMeta, entropy);
        System.out.println(l / 1000000.0);
        swap(entropy, 0, 1);
        l = builtInOperatorService.DZ_Weight(queryMeta, entropy);
        System.out.println(l / 1000000.0);

        swap(entropy, 0, 2);
        l = builtInOperatorService.DZ_Weight(queryMeta, entropy);
        System.out.println(l / 1000000.0);
    }

    private void swap(long[] entropy, int i, int j) {
        long t = entropy[i];
        entropy[i] = entropy[j];
        entropy[j] = t;
    }
}