package com.rsgisai.geohazard.subsystem.service.impl;

import com.rsgisai.geohazard.subsystem.service.LocalFileService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.mock.web.MockMultipartFile;

import java.nio.file.Path;
import java.util.Set;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicInteger;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-02-17 8:48 AM
 */
@SpringBootTest
class LocalFileServiceTest {
    @Autowired
    LocalFileService localFileService;

    AtomicInteger atomicInteger = new AtomicInteger();

    private int numberOfThreadToTest = 3;
    CountDownLatch latch = new CountDownLatch(numberOfThreadToTest);

    @Test
    void saveFile() {
        Runnable saveFileTask = new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10000; i++) {
                    int fileId = atomicInteger.incrementAndGet();
                    localFileService.saveFile("test", fileId,
                            new MockMultipartFile(
                                    "file",
                                    "test" + fileId + ".tif",
                                    "image/geotiff",
                                    "test content".getBytes()));
                }
                latch.countDown();
            }
        };
        for (int i = 0; i < numberOfThreadToTest; i++) {
            new Thread(saveFileTask).start();
        }
        try {
            latch.await();
            Set<Path> localFileSet = localFileService.getLocalFileSet();
            int size = localFileSet.size();
            System.out.println("size = " + size);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    @Test
    void clear() {
        Runnable saveFileTask = () -> {
            for (int i = 0; i < 10000; i++) {
                int fileId = atomicInteger.incrementAndGet();
                localFileService.clear("test", fileId,
                        new MockMultipartFile(
                                "file",
                                "test" + fileId + ".tif",
                                "image/geotiff",
                                "test content".getBytes()));
            }
            latch.countDown();
        };
        for (int i = 0; i < numberOfThreadToTest; i++) {
            new Thread(saveFileTask).start();
        }
        try {
            latch.await();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}