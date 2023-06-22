package com.rsgisai.geohazard.level.client;

import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.LinearModel;
import lombok.Builder;
import lombok.Data;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.awt.*;

/**
 * @author tfh, created at 2023-05-24 11:42 PM
 */
@FeignClient("geohazard-gis")
public interface LandslideActivityClient {

    @PostMapping(value = "/geohazard-gis/landslide-activity/train-xls",
            consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
    R<LinearModel> train(MultipartFile xls);

    @Data
    @Builder
    class TrainArg {
        public String path;
    }

    @PostMapping(value = "/train", consumes = MediaType.APPLICATION_FORM_URLENCODED_VALUE)
    R<LinearModel> train(@RequestBody TrainArg path);

    default R<LinearModel> train(String path) {
        return train(TrainArg.builder().path(path).build());
    }
}
