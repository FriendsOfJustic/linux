package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.dao.pgsql.LandslidePotentialDao;
import com.rsgisai.geohazard.level.entity.LandslidePotential;
import com.rsgisai.geohazard.level.entity.RiskLevel;
import com.rsgisai.geohazard.level.service.LandslidePotentialRiskLevelService;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

/**
 * @author tfh, created at 2023-06-07 10:40 PM
 */
@Service
public class LandslidePotentialRiskLevelServiceImpl implements LandslidePotentialRiskLevelService {
    private final LandslidePotentialDao landslidePotentialDao;

    public LandslidePotentialRiskLevelServiceImpl(@Qualifier("landslidePotentialDao") LandslidePotentialDao landslidePotentialDao) {
        this.landslidePotentialDao = landslidePotentialDao;
    }

    @Override
    public RiskLevel evaluate(String no) {
        // query    activityLevel
        // and      hazardLevel
        LandslidePotential landslidePotential = landslidePotentialDao.selectByNo(no);

        // convert to index
        int activityLevelIdx = getActivityLevelIdx(landslidePotential.getActivityLevel());
        int hazardLevelIdx = getHazardLevelIdx(landslidePotential.getHazardLevel());

        String riskLevel = RiskLevelMap[hazardLevelIdx][activityLevelIdx];

        RiskLevel level = new RiskLevel(no, riskLevel);

        // save
        landslidePotentialDao.updateRiskLevel(level);

        return level;
    }

    private int getHazardLevelIdx(String hazardLevel) {
        if ("低".equals(hazardLevel)) return 0;
        if ("中".equals(hazardLevel)) return 1;
        if ("高".equals(hazardLevel)) return 2;
        if ("极高".equals(hazardLevel)) return 3;
        throw new RuntimeException("not supported hazard level:" + hazardLevel);
    }

    private int getActivityLevelIdx(String activityLevel) {
        if ("低".equals(activityLevel)) return 0;
        if ("中".equals(activityLevel)) return 1;
        if ("高".equals(activityLevel)) return 2;
        if ("极高".equals(activityLevel)) return 3;
        throw new RuntimeException("not supported activity level:" + activityLevel);
    }

    public static String[][] RiskLevelMap = {
            // 危害性\活动性
            //       低,    中,   高,  极高
            /* 低 */{"低", "低", "中", "高",},
            /* 中 */{"低", "中", "高", "高",},
            /* 高 */{"中", "中", "高", "极高",},
            /* 极高*/{"中", "高", "极高", "极高",},
    };
}
