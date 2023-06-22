package com.rsgisai.geohazard.subsystem.service;

import org.springframework.web.multipart.MultipartFile;

import java.nio.file.Path;
import java.util.Set;

public interface LocalFileService {
    String GEO_TIFF_SUFFIX = ".tif";

    Set<Path> getLocalFileSet();

    /**
     * 暂存指定文件
     *
     * @param directory     文件保存相对路径（相对于配置的保存目录
     * @param fileId        避免文件保存冲突，给每个文件一个ID
     * @param multipartFile 从 Controller 过来的上传对象
     * @return 保存的文件名称
     */
    Path saveFile(String directory, Integer fileId, MultipartFile multipartFile);

    /**
     * 指定文件后缀保存文件
     *
     * @param directory     文件保存相对路径（相对于配置的保存目录
     * @param fileId        避免文件保存冲突，给每个文件一个ID
     * @param multipartFile 从 Controller 过来的上传对象
     * @param suffix        文件名后缀
     * @return 保存的文件名称
     */
    Path saveFile_(String directory, Integer fileId, MultipartFile multipartFile, String suffix);

    boolean clear(String name, Integer id, MultipartFile shp);

    boolean clear_(String directory, Integer fileId, MultipartFile multipartFile, String suffix);

    boolean clear(Path path);
}
