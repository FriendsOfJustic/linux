package com.rsgisai.geohazard.level.client;

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
    @PostMapping("/geohazard-data/result-raster/publish")
// 不要忘了添加 geohazard-data 这个 application context
    R<ResultRaster> publish(@RequestBody ResultRaster resultRaster);


    @GetMapping("/geohazard-data/result-raster/{id}")
    R<ResultRaster> selectById(@PathVariable("id") Long id);

    @GetMapping("/geohazard-data/result-raster/latest")// 不要忘了前缀/geohazard-data/result-raster
    R<ResultRaster> getLatestResultRasterInfo(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("feature") String feature);
}
