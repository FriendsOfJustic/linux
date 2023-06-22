package com.rsgisai.geohazard.level.entity.elements_at_risk;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-06-07 7:15 PM
 */
class ElementsAtRiskFineFactoryTest {

    ElementsAtRiskFineFactory elementsAtRiskFineFactory = new ElementsAtRiskFineFactory();

    @Test
    void getAllBaseClassObjects() {
        String[] strings = {
                "居民区",
                "工矿区",
                "耕地",
                "林地",
                "草地",
                "道路"
        };

        for (String name : strings) {
            ElementsAtRiskFine elementsAtRiskFine = new ElementsAtRiskFine();
            elementsAtRiskFine.setName(name);


            AbstractElementsAtRiskFine subclassObject = elementsAtRiskFineFactory.getSubclassObject(elementsAtRiskFine);
            System.out.println(
                    subclassObject
                            + "\t"
                            +
                            subclassObject.getClass().getName()
            );

        }
    }
}