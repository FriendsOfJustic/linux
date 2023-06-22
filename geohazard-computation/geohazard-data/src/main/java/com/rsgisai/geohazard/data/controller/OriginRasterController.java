package com.rsgisai.geohazard.data.controller;

import com.rsgisai.geohazard.data.service.OriginRasterService;
import com.rsgisai.geohazard.data.service.impl.AuthServiceImpl;
import com.rsgisai.geohazard.data.vo.RasterQuery;
import com.rsgisai.geohazard.system.common.OriginRaster;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.*;

/**
 * @author tfh, created at 2023-04-10 10:19 AM
 */
@RestController
@RequestMapping("/origin-raster")
public class OriginRasterController {
    @Autowired
    private OriginRasterService originRasterService;
    @Autowired
    private AuthServiceImpl authService;

    @GetMapping
    public R<List<OriginRaster>> list(OriginRaster originRaster) {
        return R.ok(originRasterService.query(originRaster));
    }

    /**
     * 需要 feature & workingAreaId
     */
    @PostMapping("/publish")
    public R<OriginRaster> publish(@RequestBody OriginRaster originRaster) throws IOException {
        Set<String> missingArgumentSet = new HashSet<String>();
        if (originRaster.getFeature() == null) missingArgumentSet.add("feature");
        if (originRaster.getWorkingAreaId() == null) missingArgumentSet.add("feature");
        if (!missingArgumentSet.isEmpty()) return R.<OriginRaster>fail("check your arguments")
                .withData(originRaster)
                .put("missingArgumentSet", missingArgumentSet);

        originRasterService.publish(originRaster);
        return R.ok(originRaster).message("数据发布成功");
    }

    @PostMapping("/upload")
    public R<OriginRaster> upload(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year,
            @RequestParam("feature") String feature,
            @RequestParam("geotiff") MultipartFile geotiff
    ) throws IOException {
        RasterQuery rasterQuery = new RasterQuery(feature, workingAreaId, year, authService.getCurrentUserId());
        long id = originRasterService.upload(geotiff, rasterQuery);
        OriginRaster data = new OriginRaster();
        data.setId(id);
        return R.ok(data);
    }

}
