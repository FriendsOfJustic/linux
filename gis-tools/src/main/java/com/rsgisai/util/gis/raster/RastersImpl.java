package com.rsgisai.util.gis.raster;

import lombok.extern.slf4j.Slf4j;
import org.springframework.web.multipart.MultipartFile;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * @author tfh, created at 2023-03-12 11:20 AM
 */
@Slf4j
public class RastersImpl implements Rasters {

    private final String localStorePath = "tmp";
    private AtomicInteger atomicInteger = new AtomicInteger();

    @Override
    public String geotiff2WkbHex(MultipartFile multipartFile) throws IOException {
        // 保存GeoTIFF并返回临时文件
        Path tmpTiffFile = saveTiff(multipartFile);
        try {
            // 创建 raster2pgsql 工具的子进程
            ProcessBuilder pb = new ProcessBuilder(
                    "raster2pgsql",
                    tmpTiffFile.toString(),
                    "ignore_me_table_name"
            );
            pb.redirectErrorStream(true);
            Process process = pb.start();
            InputStream inputStream = process.getInputStream();

            // 对 raster2pgsql 输出SQL字符串进行裁剪获取 WKB 的十六进制
            String rasterWktHex = readRasterString(inputStream);
            System.out.println("rasterWktHex = " + rasterWktHex);
            log.debug("extracted wkb hex:");
            log.debug(rasterWktHex);

            // 处理异常或正常返回
            int exitCode = process.waitFor();
            if (exitCode == 0) {
                System.out.println("Command executed successfully.");
                return rasterWktHex;
            } else {
                System.err.println("Command failed with exit code " + exitCode);
                throw new RuntimeException("geotiff2WkbHex failed.");
            }
        } catch (IOException | InterruptedException e) {
            throw new RuntimeException("geotiff2WkbHex failed.");
        } finally {
            // 清理临时文件
            boolean clear = clear(tmpTiffFile);
        }
    }

    private String readRasterString(InputStream inputStream) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        String line;
        while ((line = reader.readLine()) != null) {
            if (line.startsWith("INSERT INTO")) {
                String prefix = "VALUES ('";
                return line.substring(
                        line.indexOf(prefix) + prefix.length()
                        ,
                        line.lastIndexOf("'::raster")
                );
            }
        }
        throw new RuntimeException("Read GeoTIFF Raster Failed.");
    }

    private boolean clear(Path tmpTiffFile) {
        return tmpTiffFile.toFile().delete();
    }

    private Path saveTiff(MultipartFile multipartFile) {
        File tmp = Paths.get(localStorePath, Rasters.class.getName()).toFile();
        if (!tmp.exists()) {
            boolean mkdirs = tmp.mkdirs();
        }
        Path path = Paths.get(tmp.getAbsolutePath(), atomicInteger.incrementAndGet() + ".tif");
        try {
            multipartFile.transferTo(path);
            return path;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
