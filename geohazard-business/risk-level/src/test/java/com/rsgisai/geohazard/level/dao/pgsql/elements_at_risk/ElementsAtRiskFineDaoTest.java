package com.rsgisai.geohazard.level.dao.pgsql.elements_at_risk;

import com.rsgisai.geohazard.level.entity.elements_at_risk.AbstractElementsAtRiskFine;
import com.rsgisai.geohazard.level.entity.elements_at_risk.ElementsAtRiskFine;
import com.rsgisai.geohazard.level.entity.elements_at_risk.ElementsAtRiskFineFactory;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;
import java.util.stream.Collectors;

/**
 * @author tfh, created at 2023-06-07 5:44 PM
 */
@SpringBootTest
class ElementsAtRiskFineDaoTest {

    @Autowired
    ElementsAtRiskFineDao elementsAtRiskFineDao;
    ElementsAtRiskFineFactory elementsAtRiskFineFactory = new ElementsAtRiskFineFactory();

    @Test
    void selectByLandslidePotentialInfluence() {
        List<ElementsAtRiskFine> elementsAtRiskFines = elementsAtRiskFineDao.selectByLandslidePotentialInfluence("53011301086R");
        showCalucation(elementsAtRiskFines);
    }

    private void showCalucation(List<ElementsAtRiskFine> elementsAtRiskFines) {
        List<AbstractElementsAtRiskFine> abstractElementsAtRiskFines = elementsAtRiskFines.stream().map(elementsAtRiskFineFactory::getSubclassObject)
                .collect(Collectors.toList());

        for (AbstractElementsAtRiskFine element : abstractElementsAtRiskFines) {
            System.out.println("people:" + element.numberOfPeople()
                    + "\t"
                    + "property:" + element.amountOfProperty()
                    + "\t"
                    + element);
        }
    }

    @Test
    void selectAll() {
        List<ElementsAtRiskFine> elementsAtRiskFines = elementsAtRiskFineDao.selectAll();
        showCalucation(elementsAtRiskFines);
    }
}