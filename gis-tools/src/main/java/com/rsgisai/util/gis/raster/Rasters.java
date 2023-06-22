package com.rsgisai.util.gis.raster;

import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;

/**
 * @author tfh, created at 2023-02-17 10:11 AM
 */
public interface Rasters {

    String geotiff2WkbHex(MultipartFile inputStream) throws IOException;
}
