package com.rsgisai.geohazard.subsystem.service.impl;

import com.rsgisai.geohazard.subsystem.service.LocalFileService;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Set;
import java.util.concurrent.ConcurrentSkipListSet;

@Service
public class LocalFileServiceImpl implements LocalFileService {

    private final String localStorePath = "tmp";


    private final Set<Path> localFileSet = new ConcurrentSkipListSet<>();
//    public final Set<Path> localFileSet = new HashSet<>();// 这个 LocalFileService 处于多线程环境，为了避免不必要的麻烦，使用并发安全的 Set，而不是这个

    @Override
    public Set<Path> getLocalFileSet() {
        return localFileSet;
    }

    @Override
    public Path saveFile(String directory, Integer fileId, MultipartFile multipartFile) {
        String originalFilename = multipartFile.getOriginalFilename();
        int i = originalFilename.lastIndexOf(".");
        if (i == -1) {
            return saveFile_(directory, fileId, multipartFile, "");
        } else {
            return saveFile_(directory, fileId, multipartFile, originalFilename.substring(i));
        }
    }

    @Override
    public Path saveFile_(String directory, Integer fileId, MultipartFile multipartFile, String suffix) {
        File tmp = Paths.get(localStorePath, directory).toFile();
        if (!tmp.exists()) {
            boolean mkdirs = tmp.mkdirs();
        }
        Path path = Paths.get(tmp.getAbsolutePath(), fileId + suffix);
        try {
            multipartFile.transferTo(path);
            this.localFileSet.add(path);
            return path;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public boolean clear(String directory, Integer fileId, MultipartFile multipartFile) {
        String originalFilename = multipartFile.getOriginalFilename();
        int i = originalFilename.lastIndexOf(".");
        if (i == -1) {
            return clear_(directory, fileId, multipartFile, "");
        } else {
            return clear_(directory, fileId, multipartFile, originalFilename.substring(i));
        }
    }

    @Override
    public boolean clear_(String directory, Integer fileId, MultipartFile multipartFile, String suffix) {
        File tmp = Paths.get(localStorePath, directory).toFile();
        if (!tmp.exists()) {
            boolean mkdirs = tmp.mkdirs();
        }
        Path path = Paths.get(tmp.getAbsolutePath(), String.valueOf(fileId) + suffix);
        if (path.toFile().delete()) {
            return this.localFileSet.remove(path);
        } else {
            return false;
        }
    }

    @Override
    public boolean clear(Path path) {
        if (path.toFile().delete()) {
            return this.localFileSet.remove(path);
        }
        return false;
    }
}
