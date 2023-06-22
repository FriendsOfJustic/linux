package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.entity.LandslidePotential;
import com.rsgisai.geohazard.level.service.LandslideActivityService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.LinearModel;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.InputStreamResource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

/**
 * @author tfh, created at 2023-05-24 11:35 PM
 */
@RestController
@RequestMapping("landslide-activity")
public class LandslideActivityController {
    @Autowired
    LandslideActivityService landslideActivityService;

    @PostMapping("/train")
    public R<LinearModel> train(
            @RequestParam("xls") MultipartFile xls
    ) throws IOException {
        return R.ok(landslideActivityService.train(xls));
    }

    @PostMapping("/evaluate")
    public ResponseEntity<InputStreamResource> evaluate(
            @RequestParam("xls") MultipartFile xls
    ) throws IOException {
        Path evaluate = landslideActivityService.evaluate(xls);

        // Copy the file to a temporary location
//        Files.copy(evaluate, evaluate, StandardCopyOption.REPLACE_EXISTING);

        // Set the appropriate headers
        HttpHeaders headers = new HttpHeaders();
        headers.add(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename=evaluate.xls");

        // Create the ResponseEntity with the file and headers
        return ResponseEntity
                .ok()
                .headers(headers)
                .contentType(MediaType.APPLICATION_OCTET_STREAM)
                .body(new InputStreamResource(Files.newInputStream(evaluate)));
    }

    @PostMapping(value = "/evaluate", params = "no")
    public R<LandslidePotential> evaluate(
            @RequestParam("no") String no/* the unique identifier of landslide potential */
    ) throws IOException {
        LandslidePotential landslidePotential = landslideActivityService.evaluate(no);
        return R.ok(landslidePotential).message("活动性计算成功");
    }
}
