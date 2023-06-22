package com.rsgisai.geohazard.computation.geospatial.client;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import com.rsgisai.geohazard.system.common.GeohazardComputationJob;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.ResultRaster;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

@FeignClient("geohazard-data")// 注意不可以有斜线，即不要写成 '/geospatial-computation'
public interface ResultRasterClient {

    /**
     * 1. feature
     * 2. workingAreaId
     * 3. args
     */
    @PostMapping("/geohazard-data/result-raster/publish")// 不要忘了添加 geohazard-data 这个 application context
    R<ResultRaster> publish(@RequestBody ResultRaster resultRaster);

}
