package com.rsgisai.geohazard.level.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.rsgisai.geohazard.level.entity.LandslidePotential;
import com.rsgisai.geohazard.system.common.entity.LinearModel;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.nio.file.Path;

/**
 * @author tfh, created at 2023-05-24 11:40 PM
 */
public interface LandslideActivityService {
    LinearModel train(MultipartFile xls) throws IOException;

    Path evaluate(MultipartFile xls) throws IOException;

    LandslidePotential evaluate(String no) throws JsonProcessingException;
}
