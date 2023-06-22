package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.system.common.entity.Legend;
import com.rsgisai.util.gis.style.VectorStyles;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-05-05 10:25 AM
 */
@SpringBootTest
class LegendServiceTest {
    @Autowired
    LegendService legendService;

    @Test
    void select() {
        List<Legend> elementsAtRisk = legendService.queryByName("elements_at_risk");
        elementsAtRisk.forEach(System.out::println);
    }

    @Test
    void insert() throws ParserConfigurationException, IOException, SAXException {

        InputStream inputStream = LegendServiceTest.class.getClassLoader().getResourceAsStream("style/exposure_index.sld");
        List<Legend> legendList = VectorStyles.parse("exposure_index", inputStream);
        for (Legend legend : legendList) {
            System.out.println("legend = " + legend);
        }

        legendService.insert(legendList);
    }

}