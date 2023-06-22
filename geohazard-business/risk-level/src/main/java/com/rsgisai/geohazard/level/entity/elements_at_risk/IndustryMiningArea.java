package com.rsgisai.geohazard.level.entity.elements_at_risk;

import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-05-26 4:24 PM
 */
@Component
public class IndustryMiningArea extends AbstractElementsAtRiskFine {
    public IndustryMiningArea() {

    }

    public IndustryMiningArea(Long id, String name, String level, Double area) {
        super(id, name, level, area);
    }

    public enum Type {
        Industry,
        Mining,
    }

    @Override
    public String getCanonicalName() {
        return "工矿区";
    }

    @Override
    public long numberOfPeople() {
        return 0;
    }

    @Override
    public double amountOfProperty() {
        switch (level) {
            case "采矿":
                return area * 8000;
            case "工业":
                return area * 10_000;
            default:
                throw new RuntimeException("no such administrative division");
        }
    }

    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return new IndustryMiningArea(
                elementsAtRiskFine.id,
                elementsAtRiskFine.name,
                elementsAtRiskFine.level,
                elementsAtRiskFine.area
        );
    }
}
