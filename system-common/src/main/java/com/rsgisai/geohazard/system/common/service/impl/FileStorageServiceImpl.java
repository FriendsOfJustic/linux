package com.rsgisai.geohazard.system.common.service.impl;

import com.rsgisai.geohazard.system.common.service.FileStorageService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.concurrent.atomic.AtomicLong;

/**
 * @author tfh, created at 2023-05-25 10:23 AM
 */
@Slf4j
public class FileStorageServiceImpl implements FileStorageService {

    private final AtomicLong atomicLong = new AtomicLong();
    private final Path basePath;
    private final String TMP_DIR = "/tmp";

    public FileStorageServiceImpl(Class<?> service) {
        String name = service.getName();
        this.basePath = Paths.get(TMP_DIR, name);
        if (!Files.exists(basePath)) {
            try {
                Files.createDirectories(basePath);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    @Override
    public Path saveTmp(MultipartFile multipartFile) throws IOException {
        Path resolve = basePath.resolve(String.valueOf(atomicLong.getAndIncrement()));

        InputStream inputStream = multipartFile.getInputStream();
        Files.copy(inputStream, resolve, StandardCopyOption.REPLACE_EXISTING);

        log.info("tmp file saved to: " + resolve.toAbsolutePath());
        return resolve;
    }

    @Override
    public void removeTmp(Path hello) throws IOException {
        Files.delete(hello);
    }
}
