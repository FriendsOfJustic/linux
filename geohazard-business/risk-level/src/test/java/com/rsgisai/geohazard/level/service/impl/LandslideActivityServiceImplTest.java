package com.rsgisai.geohazard.level.service.impl;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.mock.web.MockMultipartFile;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Path;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-05-25 4:59 PM
 */
@SpringBootTest
class LandslideActivityServiceImplTest {

    @Autowired
    LandslideActivityServiceImpl landslideActivityServiceImpl;

    @Test
    void evaluate() throws IOException {
        FileInputStream fileInputStream = new FileInputStream("D:\\Repository\\Projects\\RERSSIL\\geohazard\\geohazard-gis\\algorithm\\landslide_demo.xls");
        MockMultipartFile mockMultipartFile = new MockMultipartFile("xls", "what ever", "xls", fileInputStream);
        Path evaluate = landslideActivityServiceImpl.evaluate(mockMultipartFile);
        System.out.println("evaluate = " + evaluate);
    }
}