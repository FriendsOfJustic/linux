package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.dao.pgsql.elements_at_risk.ElementsAtRiskFineDao;
import com.rsgisai.geohazard.level.entity.PersonnelPropertyLoss;
import com.rsgisai.geohazard.level.entity.elements_at_risk.AbstractElementsAtRiskFine;
import com.rsgisai.geohazard.level.entity.elements_at_risk.ElementsAtRiskFine;
import com.rsgisai.geohazard.level.entity.elements_at_risk.ElementsAtRiskFineFactory;
import com.rsgisai.geohazard.level.service.PersonnelPropertyLossService;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * @author tfh, created at 2023-06-07 5:14 PM
 */
@Service
public class PersonnelPropertyLossServiceImpl implements PersonnelPropertyLossService {
    private final ElementsAtRiskFineDao elementsAtRiskFineDao;
    ElementsAtRiskFineFactory elementsAtRiskFineFactory = new ElementsAtRiskFineFactory();

    public PersonnelPropertyLossServiceImpl(@Qualifier("elementsAtRiskFineDao") ElementsAtRiskFineDao elementsAtRiskFineDao) {
        this.elementsAtRiskFineDao = elementsAtRiskFineDao;
    }

    @Override
    public PersonnelPropertyLoss calculateLoss(String potentialInfluenceNo) {
        // query all elements-at-risk
        List<ElementsAtRiskFine> elementsAtRiskFines = elementsAtRiskFineDao.selectByLandslidePotentialInfluence(potentialInfluenceNo);
        // convert to actual type
        List<AbstractElementsAtRiskFine> actualElementsAtRisks = elementsAtRiskFines.stream().map(elementsAtRiskFineFactory::getSubclassObject)
                .collect(Collectors.toList());
        // calculate personnel loss
        long personnelLoss = actualElementsAtRisks.stream()
                .map(AbstractElementsAtRiskFine::numberOfPeople)
                .mapToLong(Long::new).sum();
        // calculate property loss
        double propertyLoss = actualElementsAtRisks.stream()
                .map(AbstractElementsAtRiskFine::amountOfProperty)
                .mapToDouble(Double::new).sum();
        // 计算（危害等级）
        String hazardLevel = toHazardLevel(personnelLoss, propertyLoss);
        // 组装结果
        PersonnelPropertyLoss personnelPropertyLoss = new PersonnelPropertyLoss(
                potentialInfluenceNo,
                personnelLoss, propertyLoss, hazardLevel);
        // save result
        elementsAtRiskFineDao.updatePersonnelPropertyLoss(personnelPropertyLoss);
        // return result
        return personnelPropertyLoss;
    }

    public static String[][] HazardLevelMap = {
            // 威胁财产\威胁人员    [0,10) [10, 100) [100, 1000) [1000, inf)
            /* [0,      500万)  */{"低", "低", "中", "高",},
            /* [500万,  1000万) */{"低", "中", "高", "高",},
            /* [1000万, 5000万) */{"中", "中", "高", "极高",},
            /* [5000万, inf)    */{"中", "高", "极高", "极高",},
    };

    private String toHazardLevel(long personnelLoss, double propertyLoss) {
        int propertyLevel = getPropertyLevel(propertyLoss);
        int personnelLevel = getPersonnelLevel(personnelLoss);
        return HazardLevelMap[propertyLevel][personnelLevel];
    }

    private int getPersonnelLevel(long personnelLoss) {
        if (personnelLoss < 10) return 0;
        if (personnelLoss < 100) return 1;
        if (personnelLoss < 1000) return 2;
        return 3;
    }

    private int getPropertyLevel(double propertyLoss) {
        if (propertyLoss < 500 * 10000) return 0;
        if (propertyLoss < 1000 * 10000) return 1;
        if (propertyLoss < 5000 * 10000) return 2;
        return 3;
    }
}
