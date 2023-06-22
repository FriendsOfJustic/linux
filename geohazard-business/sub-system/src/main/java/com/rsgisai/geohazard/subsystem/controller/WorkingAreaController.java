package com.rsgisai.geohazard.subsystem.controller;

import com.rsgisai.geohazard.entity.WorkingArea;
import com.rsgisai.geohazard.subsystem.exception.WorkingAreaException;
import com.rsgisai.geohazard.subsystem.service.WorkingAreaService;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.util.gis.exception.MultiPolygonException;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;
import java.util.List;
import java.util.Objects;

@RestController
@RequestMapping("/working-area")
public class WorkingAreaController {
    @Resource
    private WorkingAreaService workingAreaService;

    @GetMapping
    public R<List<WorkingArea>> list() {
        return R.success(workingAreaService.queryAll());
    }

    @PostMapping("upload")
    public R<WorkingArea> uploadAndCheck(
            @RequestParam("name") String workingAreaName,
            @RequestParam("shp") MultipartFile shp,
            @RequestParam("dbf") MultipartFile dbf,
            @RequestParam("shx") MultipartFile shx
    ) throws IOException, WorkingAreaException, MultiPolygonException {
        String shpOriginalFilename = shp.getOriginalFilename();
        String dbfOriginalFilename = dbf.getOriginalFilename();
        String shxOriginalFilename = shx.getOriginalFilename();
        // 数据检查
        // 1. 文件名后缀检查
        if (shxOriginalFilename == null) return R.fail("缺少文件名");
        if (!(shxOriginalFilename.endsWith(".shx") &&
                Objects.requireNonNull(shpOriginalFilename).endsWith(".shp") &&
                Objects.requireNonNull(dbfOriginalFilename).endsWith(".dbf")))
            return R.fail("shp 文件后缀不正确");

        // 2. shape 三个文件一致性检查，检查三个文件名是否一样
        shpOriginalFilename = shpOriginalFilename.substring(0, shpOriginalFilename.lastIndexOf(".") + 1);
        dbfOriginalFilename = dbfOriginalFilename.substring(0, dbfOriginalFilename.lastIndexOf(".") + 1);
        shxOriginalFilename = shxOriginalFilename.substring(0, shxOriginalFilename.lastIndexOf(".") + 1);
        if (!(shpOriginalFilename.equals(dbfOriginalFilename) &&
                shpOriginalFilename.equals(shxOriginalFilename)))
            return R.fail("shp 文件名不一致");


        // 将矢量研究区入库
        WorkingArea workingArea = workingAreaService.save(shp, dbf, shx, workingAreaName);

        return R.success(workingArea);
    }

    @PostMapping("change")
    public R<WorkingArea> change(@RequestParam("workingAreaId") Long workingAreaId) {
//        SysUser user = authService.getLoginUser();
//        WorkingArea workingArea = workingAreaService.changeUserWorkingArea(
//                user.getId(),workingAreaId);
        return R.success(null);
    }

}
