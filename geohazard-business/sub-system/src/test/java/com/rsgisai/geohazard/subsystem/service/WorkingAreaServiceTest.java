package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.entity.WorkingArea;
import com.rsgisai.geohazard.subsystem.exception.WorkingAreaException;
import com.rsgisai.util.gis.exception.MultiPolygonException;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.mock.web.MockMultipartFile;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

import java.io.IOException;
import java.io.InputStream;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class WorkingAreaServiceTest {
    @Resource
    private WorkingAreaService workingAreaService;


    @Test
    void save() throws IOException, WorkingAreaException, MultiPolygonException {
        ClassLoader classLoader = this.getClass().getClassLoader();
        InputStream shpIs = classLoader.getResourceAsStream("interest_demo/interest_demo.shp");
        InputStream dbfIs = classLoader.getResourceAsStream("interest_demo/interest_demo.dbf");
        InputStream shxIs = classLoader.getResourceAsStream("interest_demo/interest_demo.shx");

        MultipartFile shp = new MockMultipartFile("shp", "sa.shp", "", shpIs);
        MultipartFile dbf = new MockMultipartFile("dbf", "sa.dbf", "", dbfIs);
        MultipartFile shx = new MockMultipartFile("shx", "sa.shx", "", shxIs);

        WorkingArea workingArea = workingAreaService.save(shp, dbf, shx, "蒙东");
        System.out.println("workingArea = " + workingArea);
    }
}