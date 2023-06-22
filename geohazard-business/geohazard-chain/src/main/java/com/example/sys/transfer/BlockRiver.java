package com.example.sys.transfer;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.bind.annotation.RequestParam;


//0.976+0.001*坡高-0.739*宽深比-0.003*河宽指数+0.68*不对称系数+0.049*平均坡度-0.268*剖面面积（KM^2）
@Data
@AllArgsConstructor
@NoArgsConstructor
public class BlockRiver {
    @JsonProperty("id")
    private String id;   //隐患点编号

    @JsonProperty("SlopeHeight")
    private  Double SlopeHeight;    //坡高

    @JsonProperty("WithDepthRatio")
    private  Double WithDepthRatio;  //宽深比

    @JsonProperty("WithIndex")
    private  Double WithIndex;         //河宽指数

    @JsonProperty("BuDuiChengRatio")
    private Double BuDuiChengRatio;    //不对称系数

    @JsonProperty("AverageSlop")
    private  Double AverageSlop;    //平均坡度

    @JsonProperty("Area")
    private  Double Area;          //剖面面积

    @Override
    public String toString() {
        return "BlockRiver{" +
                "id='" + id + '\'' +
                ", SlopeHeight=" + SlopeHeight +
                ", WithDepthRatio=" + WithDepthRatio +
                ", WithIndex=" + WithIndex +
                ", BuDuiChengRatio=" + BuDuiChengRatio +
                ", AverageSlop=" + AverageSlop +
                ", Area=" + Area +
                '}';
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Double getSlopeHeight() {
        return SlopeHeight;
    }

    public void setSlopeHeight(Double slopeHeight) {
        SlopeHeight = slopeHeight;
    }

    public Double getWithDepthRatio() {
        return WithDepthRatio;
    }

    public void setWithDepthRatio(Double withDepthRatio) {
        WithDepthRatio = withDepthRatio;
    }

    public Double getWithIndex() {
        return WithIndex;
    }

    public void setWithIndex(Double withIndex) {
        WithIndex = withIndex;
    }

    public Double getBuDuiChengRatio() {
        return BuDuiChengRatio;
    }

    public void setBuDuiChengRatio(Double buDuiChengRatio) {
        BuDuiChengRatio = buDuiChengRatio;
    }

    public Double getAverageSlop() {
        return AverageSlop;
    }

    public void setAverageSlop(Double averageSlop) {
        AverageSlop = averageSlop;
    }

    public Double getArea() {
        return Area;
    }

    public void setArea(Double area) {
        Area = area;
    }
}
