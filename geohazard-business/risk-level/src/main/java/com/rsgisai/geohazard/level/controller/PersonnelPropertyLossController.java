package com.rsgisai.geohazard.level.controller;

import com.rsgisai.geohazard.level.entity.PersonnelPropertyLoss;
import com.rsgisai.geohazard.level.service.PersonnelPropertyLossService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * @author tfh, created at 2023-06-07 4:27 PM
 */
@RestController
@RequestMapping("personnel-property-loss")
public class PersonnelPropertyLossController {

    @Autowired
    PersonnelPropertyLossService personnelPropertyLossService;

    /**
     * 人员财产损失(危害性)计算
     */
    @PostMapping
    public R<?> calculatePersonnelPropertyLoss(
            String no/* the unique identifier of landslide potential */
    ) {

        PersonnelPropertyLoss loss = personnelPropertyLossService.calculateLoss(no);

        return R.ok(loss).message("隐患#" + no + " 人员财产评估更新成功");
    }
}
