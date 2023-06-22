package com.rsgisai.geohazard.data.service;

import com.rsgisai.geohazard.system.common.OriginRaster;
import com.rsgisai.geohazard.system.common.ResultRaster;
import org.springframework.beans.factory.annotation.Autowired;

import java.io.IOException;
import java.util.List;

public interface ResultRasterService {
    int publish(ResultRaster resultRaster) throws IOException;

    //List<ResultRaster> query(ResultRaster resultRaster);
}
