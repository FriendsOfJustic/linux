package com.rsgisai.geohazard.statistic.entity;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * 注意：为了使进行JSON序列化的时候输出大写的 L H V，需要给对应的 getter 上面添加 @JsonProperty("L") 注解
 * <p>
 * 如果将 @JsonProperty 放在字段上，那么会同时根据 字段和 getter 进行序列化，也就是重复输出大写、小写。
 * 推测，其机制是默认按照 getter 进行序列化，如果字段上面有 @JsonProperty 则同时序列化字段和 getter。
 * 因为getter 的 camel case 的原因，导致出现 L H V 序列化的时候变成了小写。
 */
@ToString
public class LandslideHazard {
    Integer id;
    LocalDateTime dateTime;
    String name;
    GeoPoint point;

    Double L;
    Double H;
    Double V;
    Integer rockSoilType;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public LocalDateTime getDateTime() {
        return dateTime;
    }

    public void setDateTime(LocalDateTime dateTime) {
        this.dateTime = dateTime;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public GeoPoint getPoint() {
        return point;
    }

    public void setPoint(GeoPoint point) {
        this.point = point;
    }

    @JsonProperty("L")
    public Double getL() {
        return L;
    }

    public void setL(Double l) {
        L = l;
    }

    @JsonProperty("H")
    public Double getH() {
        return H;
    }

    public void setH(Double h) {
        H = h;
    }

    @JsonProperty("V")
    public Double getV() {
        return V;
    }

    public void setV(Double v) {
        V = v;
    }

    public Integer getRockSoilType() {
        return rockSoilType;
    }

    public void setRockSoilType(Integer rockSoilType) {
        this.rockSoilType = rockSoilType;
    }
}
