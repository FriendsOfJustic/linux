package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.NoArgsConstructor;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-05-26 4:29 PM
 */
@NoArgsConstructor
@Component
public class ForestArea extends AbstractElementsAtRiskFine {
    @Override
    public String getCanonicalName() {
        return "林地";
    }

    @Override
    public long numberOfPeople() {
        return 0;
    }

    @Override
    public double amountOfProperty() {
        return area * 150;
    }


    public ForestArea(Long id, String name, String level, Double area) {
        super(id, name, level, area);
    }

    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return new ForestArea(
                elementsAtRiskFine.id,
                elementsAtRiskFine.name,
                elementsAtRiskFine.level,
                elementsAtRiskFine.area
        );
    }
}
