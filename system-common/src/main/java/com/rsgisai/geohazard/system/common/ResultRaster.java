package com.rsgisai.geohazard.system.common;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.system.common.util.ResultRasterLayers;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.SortedMap;
import java.util.TreeMap;

@Data
public class ResultRaster {

    private static final ObjectMapper objectMapper = new ObjectMapper();

    public Long id;
    public Long workingAreaId;
    public String feature;
    public String algorithm;
    public SortedMap<String, Object> arguments = new TreeMap<>();

    // 辅助
    private String algorithmArgs;

    public synchronized String calculateAlgorithmArgs() {
        try {
            if (algorithmArgs == null) {
                if (arguments == null) arguments = new TreeMap<>();
                algorithmArgs = objectMapper.writeValueAsString(arguments);
            }
        } catch (JsonProcessingException e) {
            throw new RuntimeException(e);
        }
        return algorithmArgs;
    }

    // geoserver 相关
    private String layerName;

    /**
     * 由
     * String feature
     * Long workingAreaId
     * SortedMap[String, Object] args
     * 计算出来
     */
    public String calculateLayerName() {
        if (feature == null) throw new RuntimeException("feature is needed for generate layer name.");
        if (workingAreaId == null) throw new RuntimeException("working area id is needed for generate layer name.");
        try {
            if (layerName != null && !layerName.equals("")) return layerName;
            return ResultRasterLayers.getLayerName(this);
        } catch (JsonProcessingException e) {
            throw new RuntimeException(e);
        }
    }

    // meta data
    public Long createBy;
    public Long modifyBy;
    public LocalDateTime createTime;
    public LocalDateTime modifyTime;
}
