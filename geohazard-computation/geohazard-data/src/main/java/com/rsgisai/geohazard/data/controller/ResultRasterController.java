package com.rsgisai.geohazard.data.controller;


import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.data.dao.pgsql.ResultRasterDao;
import com.rsgisai.geohazard.data.service.ResultRasterService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.ResultRaster;
import com.rsgisai.geohazard.system.common.util.ResultRasterLayers;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/result-raster")
public class ResultRasterController {
    @Autowired
    private ResultRasterService resultRasterService;

    @Autowired
    private ObjectMapper objectMapper;

    @Autowired
    private ResultRasterDao resultRasterDao;

    private Base64.Encoder encoder = Base64.getEncoder();

    //查询所有数据
    @GetMapping({
            "/selectAll",
            ""
    })
    public R<List<ResultRaster>> selectAll() {
        //return R.ok(resultRasterService.query(resultRaster));
        return R.ok(resultRasterDao.selectAll());
    }

    @GetMapping("/latest")
    public R<ResultRaster> getLatestResultRasterInfo(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("feature") String feature) {
        ResultRaster resultRaster = resultRasterDao.selectLatest(workingAreaId, feature);
        return R.ok(resultRaster);
    }

    //根据id来查询
    @GetMapping("/{id}")
    public R<ResultRaster> selectById(@PathVariable("id") Long id) {
        return R.ok(resultRasterDao.selectById(id));
    }

    /**
     * 1. feature
     * 2. workingAreaId
     * 3. args
     */
    @PostMapping("/publish")
    public R<ResultRaster> publish(@RequestBody ResultRaster resultRaster) throws IOException {
        resultRasterService.publish(resultRaster);
        return R.ok(resultRaster).message("数据发布成功");
    }

}
