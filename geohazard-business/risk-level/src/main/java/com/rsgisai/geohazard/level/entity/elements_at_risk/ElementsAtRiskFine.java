package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author tfh, created at 2023-05-26 4:16 PM
 */
@EqualsAndHashCode(callSuper = true)
@Data
public class ElementsAtRiskFine extends AbstractElementsAtRiskFine {

    Long id;
    String name;
    String level;
    Double area;

    @Override
    public String getCanonicalName() {
        return "";
    }

    @Override
    public long numberOfPeople() {
        throw new RuntimeException("implemented by subclasses");
    }

    @Override
    public double amountOfProperty() {
        throw new RuntimeException("implemented by subclasses");
    }

    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return elementsAtRiskFine;
    }
}
