package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.AllArgsConstructor;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-05-26 4:28 PM
 */
@Component
public class CropArea extends AbstractElementsAtRiskFine {

    public CropArea() {
    }

    public CropArea(Long id, String name, String level, Double area) {
        super(id, name, level, area);
    }

    @Override
    public String getCanonicalName() {
        return "耕地";
    }

    @Override
    public long numberOfPeople() {
        return 0;
    }

    @Override
    public double amountOfProperty() {
        return area * 200;
    }


    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return new CropArea(
                elementsAtRiskFine.id,
                elementsAtRiskFine.name,
                elementsAtRiskFine.level,
                elementsAtRiskFine.area
        );
    }
}
