package com.rsgisai.geohazard.level.entity.elements_at_risk;

import lombok.NoArgsConstructor;
import org.springframework.stereotype.Component;

/**
 * @author tfh, created at 2023-05-26 4:29 PM
 */
@Component// register to ElementsAtRiskFineFactory
@NoArgsConstructor
public class RoadArea extends AbstractElementsAtRiskFine {
    public enum Level {
        Highway,
        Provincial,
        Country,
        Township
    }

    @Override
    public String getCanonicalName() {
        return "道路";
    }

    @Override
    public long numberOfPeople() {
        return 0;
    }

    @Override
    public double amountOfProperty() {
        switch (level) {
            case "高速公路":
                return area * 1_000_000;
            case "省级":
                return area * 50_000;
            case "县级":
                return area * 10_000;
            case "乡级":
                return area * 1_000;
            default:
                throw new RuntimeException("no such administrative division");
        }
    }


    public RoadArea(Long id, String name, String level, Double area) {
        super(id, name, level, area);
    }

    @Override
    public AbstractElementsAtRiskFine clone(ElementsAtRiskFine elementsAtRiskFine) {
        return new RoadArea(
                elementsAtRiskFine.id,
                elementsAtRiskFine.name,
                elementsAtRiskFine.level,
                elementsAtRiskFine.area
        );
    }
}
