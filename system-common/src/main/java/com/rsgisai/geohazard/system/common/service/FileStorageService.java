package com.rsgisai.geohazard.system.common.service;

import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.nio.file.Path;

/**
 * @author tfh, created at 2023-05-25 10:23 AM
 */
public interface FileStorageService {
    Path saveTmp(MultipartFile multipartFile) throws IOException;

    void removeTmp(Path hello) throws IOException;
}
