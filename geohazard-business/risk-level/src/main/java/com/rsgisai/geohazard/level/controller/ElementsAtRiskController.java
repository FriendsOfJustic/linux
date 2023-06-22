package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.dao.pgsql.ElementsAtRiskDao;
import com.rsgisai.geohazard.level.entity.ElementsAtRisk;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * @author tfh, created at 2023-02-09 4:51 PM
 */
@RestController
@RequestMapping("/elements-at-risk")
public class ElementsAtRiskController {

    @Resource
    private ElementsAtRiskDao elementsAtRiskDao;

    @GetMapping
    public R<List<ElementsAtRisk>> list(ElementsAtRisk elementsAtRisk) {
        return R.success(elementsAtRiskDao.select(elementsAtRisk));
    }
}
