package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.service.impl.PublishServiceImpl;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import com.rsgisai.geohazard.level.service.RasterService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;

/**
 * @author tfh, created at 2023-02-16 4:52 PM
 */
@RestController
@RequestMapping("/publish")
public class PublishController {

    @Autowired
    private RasterService rasterService;
    @Autowired
    private PublishServiceImpl publishService;

    @PostMapping("/raster")
    public R<RasterQueryVo> publishRaster(@RequestBody RasterQueryVo rasterQueryVo) throws IOException {

        if ("evaluation".equalsIgnoreCase(rasterQueryVo.feature)) {
            publishService.publishEvaluation(rasterQueryVo);
        } else {
            publishService.publishRaster(rasterQueryVo);
        }

        return R.success(rasterQueryVo).message("数据发布成功");
    }
}
