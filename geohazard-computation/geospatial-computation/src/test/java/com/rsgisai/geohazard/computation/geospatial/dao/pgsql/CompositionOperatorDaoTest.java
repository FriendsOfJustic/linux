package com.rsgisai.geohazard.computation.geospatial.dao.pgsql;

import com.rsgisai.geohazard.system.common.CompositionOperator;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class CompositionOperatorDaoTest {
    @Autowired
    CompositionOperatorDao compositionOperatorDao;

    @Test
    void selectOne() {
        CompositionOperator compositionOperator = new CompositionOperator();
        compositionOperator.name = "b";
        compositionOperator = compositionOperatorDao.selectOne(compositionOperator);
        System.out.println("compositionOperator = " + compositionOperator);
    }
}