package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.vo.RasterQueryVo;

/**
 * @author tfh, created at 2023-02-20 2:51 PM
 */
public interface StyleService {
    String parseStyleName(RasterQueryVo rasterQueryVo);
}
