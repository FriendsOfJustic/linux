package com.rsgisai.geohazard.subsystem.service.impl;

import com.rsgisai.geohazard.entity.WorkingArea;
import com.rsgisai.geohazard.subsystem.dao.pgsql.WorkingAreaDao;
import com.rsgisai.geohazard.subsystem.exception.WorkingAreaException;
import com.rsgisai.geohazard.subsystem.service.LocalFileService;
import com.rsgisai.geohazard.subsystem.service.WorkingAreaService;
import com.rsgisai.util.gis.ShapeFiles;
import com.rsgisai.util.gis.exception.MultiPolygonException;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;
import java.nio.file.Path;
import java.util.List;

@Service
public class WorkingAreaServiceImpl implements WorkingAreaService {
    @Resource
    private LocalFileService localFileService;
    @Resource
    private WorkingAreaDao workingAreaDao;

//    @Resource
//    private UserWorkingAreaDao userWorkingAreaDao;

    @Transactional
    @Override
    public WorkingArea save(MultipartFile shp, MultipartFile dbf, MultipartFile shx, String workingAreaName) throws WorkingAreaException, IOException, MultiPolygonException {

        WorkingArea workingArea = new WorkingArea(workingAreaName);
        Integer r = workingAreaDao.insert(workingArea);
        if (r == null) throw new WorkingAreaException("insert failed.");
        Integer id = workingArea.getId();

        localFileService.saveFile(WorkingArea.class.getName(), id, dbf);
        localFileService.saveFile(WorkingArea.class.getName(), id, shx);
        Path path = localFileService.saveFile(WorkingArea.class.getName(), id, shp);


//        String wkt = ShapeFiles.toWktSinglePolygon(path.toFile()); // version 1 使用单个Polygon表示研究区
        String wkt = ShapeFiles.toWktMultiPolygon(path.toFile());; // version 2 使用 MultiPolygon 表示研究区，因为有的研究区是不连续的

        localFileService.clear(WorkingArea.class.getName(), id, shp);
        localFileService.clear(WorkingArea.class.getName(), id, shx);
        localFileService.clear(WorkingArea.class.getName(), id, dbf);

        workingArea.setWkt(wkt);
        workingAreaDao.update(workingArea);

        return workingArea;
    }

    @Override
    public WorkingArea changeUserWorkingArea(Integer workingAreaId) {
//        userWorkingAreaDao.updateOrInsert(userId, workingAreaId);
        WorkingArea workingArea = new WorkingArea();
        workingArea.setId(workingAreaId);
        return workingArea;
    }

    @Override
    public List<WorkingArea> queryAll() {
        return workingAreaDao.select();
    }
}
