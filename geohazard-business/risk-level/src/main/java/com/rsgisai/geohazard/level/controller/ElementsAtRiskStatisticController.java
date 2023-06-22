package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.entity.ElementsAtRisk;
import com.rsgisai.geohazard.level.exception.ElementsAtRiskStatisticException;
import com.rsgisai.geohazard.level.service.ElementsAtRiskStatisticService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.entity.InfluencedElementsAtRisk;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * @author tfh, created at 2023-04-25 10:36 PM
 */
@RestController
@RequestMapping("/elements-at-risk-statistic")
public class ElementsAtRiskStatisticController {
    private final ElementsAtRiskStatisticService elementsAtRiskStatisticService;

    public ElementsAtRiskStatisticController(ElementsAtRiskStatisticService elementsAtRiskStatisticService) {
        this.elementsAtRiskStatisticService = elementsAtRiskStatisticService;
    }

    @GetMapping("/influenced-elements-at-risk/is-calculated")
    public R<Boolean> isCalculated(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year
    ) {
        boolean b = elementsAtRiskStatisticService.iearCalculated(workingAreaId, year);
        return R.ok(b);
    }

    @GetMapping("/influenced-elements-at-risk/GeoJSON")
    public R<List<InfluencedElementsAtRisk>> iearGeoJson(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year
    ) {
        List<InfluencedElementsAtRisk> influencedElementsAtRisks = elementsAtRiskStatisticService.iearGeoJson(workingAreaId, year);
        return R.ok(influencedElementsAtRisks);
    }

    @PostMapping("/influenced-elements-at-risk/calculate")
    public R<Long> iearCalculate(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year
    ) {
        long n = elementsAtRiskStatisticService.iearDoCalculate(workingAreaId, year);
        return R.ok(n).message("计算成功，共" + n + "个承灾体受影响");
    }

    @PostMapping("/influenced-elements-at-risk/exposure_index")
    public R<Long> calculateExposureIndex(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year
    ) {
        long n = elementsAtRiskStatisticService.calculateExposureIndex(workingAreaId, year);
        return R.ok(n).message("计算成功，共" + n + "个承灾体的‘风险暴露指数’被计算");
    }

    @GetMapping("/influenced-elements-at-risk/distribution")
    public R<List<ElementsAtRisk>> getDistribution(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year
    ) {
        if (!elementsAtRiskStatisticService.iearCalculated(workingAreaId, year)) {
            throw new ElementsAtRiskStatisticException("受影响承灾体未计算，无法进行承灾体分布统计");
        }
        List<ElementsAtRisk> elementsAtRisksDistribution =
                elementsAtRiskStatisticService.distributionStatistic(workingAreaId, year);
        return R.ok(elementsAtRisksDistribution);
    }

    @DeleteMapping("/influenced-elements-at-risk")
    public R<Long> deleteIear(
            @RequestParam("workingAreaId") Long workingAreaId,
            @RequestParam("year") Integer year
    ) {
        long n = elementsAtRiskStatisticService.deleteInfluencedElementsAtRisk(workingAreaId, year);
        return R.ok(n).message(n + "条记录被删除");
    }

    @PostMapping("/influenced-elements-at-risk-clip/calculate")
    public R<Long> calculateIearClipped(
            @RequestParam("potential_id") String potentialId
    ) {
        long n = elementsAtRiskStatisticService.calculateIearClipped(potentialId);
        return R.ok(n).message("计算成功，共" + n + "个承灾体受影响");
    }

    /**
     * 获取隐患影响范围内承灾体分布统计
     *
     * @param potentialId 隐患ID
     */
    @GetMapping("/influenced-elements-at-risk-clip/distribute")
    public R<List<ElementsAtRisk>> iearClippedDistribute(
            @RequestParam("potential_id") String potentialId
    ) {
        List<ElementsAtRisk> distribute = elementsAtRiskStatisticService.iearClippedDistribute(potentialId);
        return R.ok(distribute);
    }
}
