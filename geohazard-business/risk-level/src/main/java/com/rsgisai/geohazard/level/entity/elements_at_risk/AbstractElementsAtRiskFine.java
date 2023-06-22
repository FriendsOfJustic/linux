package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;
import lombok.ToString;

/**
 * @author tfh, created at 2023-05-26 4:16 PM
 */
@NoArgsConstructor
@AllArgsConstructor
@ToString
public abstract class AbstractElementsAtRiskFine {

    Long id;
    String name;
    String level;
    Double area;

    abstract public String getCanonicalName();

    abstract public long numberOfPeople();

    abstract public double amountOfProperty();

    abstract public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine);
}
