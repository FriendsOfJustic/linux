package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.NoArgsConstructor;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-06-07 6:08 PM
 */
@Component// register to ElementsAtRiskFineFactory
@NoArgsConstructor
public class GrasslandArea extends AbstractElementsAtRiskFine {

    @Override
    public String getCanonicalName() {
        return "草地";
    }

    @Override
    public long numberOfPeople() {
        return 0;
    }

    @Override
    public double amountOfProperty() {
        return 0;
    }

    public GrasslandArea(Long id, String name, String level, Double area) {
        super(id, name, level, area);
    }

    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return new GrasslandArea(
                elementsAtRiskFine.id,
                elementsAtRiskFine.name,
                elementsAtRiskFine.level,
                elementsAtRiskFine.area
        );
    }
}
