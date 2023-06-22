package com.rsgisai.geohazard.data.dao.pgsql;

import com.rsgisai.geohazard.system.common.ResultRaster;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.TreeMap;

/**
 * @author tfh, created at 2023-04-13 9:40 AM
 */
@SpringBootTest
class ResultRasterDaoTest {
    @Autowired
    ResultRasterDao resultRasterDao;

    @Test
    void fetchRasterTiff() throws IOException {

        long resultRasterId = 21L;

        byte[] bytes = resultRasterDao.fetchRasterTiffById(resultRasterId).getTiff();

        FileOutputStream fileOutputStream = new FileOutputStream("D:/tmp/fetch.sus.tif");
        fileOutputStream.write(bytes);

        fileOutputStream.close();
    }


    @Test
    void selectByAlgorithm() {
        ResultRaster resultRaster = new ResultRaster();
        resultRaster.workingAreaId = 1L;
        resultRaster.feature = "susceptibility";
        resultRaster.algorithm = "GH_Susceptibility";
        resultRaster.arguments = new TreeMap<String, Object>() {
            {
                put("aspectNumberClasses", 7);
                put("demNumberClasses", 5);
                put("outNumberClasses", 4);
                put("slopeNumberClasses", 6);
            }
        };

        resultRaster = resultRasterDao.selectByAlgorithm(resultRaster);
        System.out.println("resultRaster = " + resultRaster);
    }

    @Test
    void selectById(){
        ResultRaster resultRaster = resultRasterDao.selectById(44L);
        System.out.println("resultRaster = " + resultRaster);
    }
}