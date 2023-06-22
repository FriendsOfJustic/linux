package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.Data;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-05-26 4:12 PM
 */
@Component
public class ResidentialArea extends AbstractElementsAtRiskFine {
    @Override
    public String getCanonicalName() {
        return "居民区";
    }

    @Override
    public long numberOfPeople() {
        switch (level) {
            case "村":
                return 4;
            case "乡镇":
                return 8;
            case "城区":
                return 15;
            default:
                throw new RuntimeException("no such administrative division");
        }
    }

    @Override
    public double amountOfProperty() {
        switch (level) {
            case "村":
                return area * 1000;
            case "乡镇":
                return area * 2000;
            case "城区":
                return area * 8000;
            default:
                throw new RuntimeException("no such administrative division");
        }
    }

    public ResidentialArea() {
    }

    public ResidentialArea(Long id, String name, String level, Double area) {
        super(id, name, level, area);
    }

    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return new ResidentialArea(
                elementsAtRiskFine.id,
                elementsAtRiskFine.name,
                elementsAtRiskFine.level,
                elementsAtRiskFine.area
        );
    }
}
