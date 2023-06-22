package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.entity.WorkingArea;
import com.rsgisai.geohazard.subsystem.exception.WorkingAreaException;
import com.rsgisai.util.gis.exception.MultiPolygonException;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

public interface WorkingAreaService {
    WorkingArea save(MultipartFile shp, MultipartFile dbf, MultipartFile shx, String workingAreaName) throws WorkingAreaException, IOException, MultiPolygonException;


    WorkingArea changeUserWorkingArea(Integer workingAreaId);

    List<WorkingArea> queryAll();

}
