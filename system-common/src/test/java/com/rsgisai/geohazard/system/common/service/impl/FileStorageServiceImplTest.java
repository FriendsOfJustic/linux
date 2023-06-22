package com.rsgisai.geohazard.system.common.service.impl;

import com.rsgisai.geohazard.system.common.service.FileStorageService;
import org.junit.jupiter.api.Test;
import org.springframework.mock.web.MockMultipartFile;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Path;
import java.util.concurrent.TimeUnit;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-05-25 11:15 AM
 */
class FileStorageServiceImplTest {
    FileStorageServiceImpl fileStorageServiceImpl = new FileStorageServiceImpl(FileStorageServiceImplTest.class);

    @Test
    void saveTmp() throws IOException, InterruptedException {
        Path hello = fileStorageServiceImpl.saveTmp(
                new MockMultipartFile("hello", "hello world!".getBytes())
        );
        System.out.println("hello = " + hello);

        TimeUnit.SECONDS.sleep(5);

        fileStorageServiceImpl.removeTmp(hello);
        System.out.println("cleared");

        hello = fileStorageServiceImpl.saveTmp(
                new MockMultipartFile("hello", "hello world!2".getBytes())
        );
        System.out.println("hello = " + hello);

        TimeUnit.SECONDS.sleep(5);

        fileStorageServiceImpl.removeTmp(hello);
        System.out.println("cleared");

    }
}