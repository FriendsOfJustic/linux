package com.example.sys.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class WaterVolume {
    private BigDecimal area;
    private BigDecimal count;
    private BigDecimal sum_dem;
    private  BigDecimal per_area;


    public BigDecimal getPer_area() {
        return per_area;
    }

    public void setPer_area(BigDecimal per_area) {
        this.per_area = per_area;
    }



    @Override
    public String toString() {
        return "WaterVolume{" +
                "area=" + area +
                ", count=" + count +
                ", sum_dem=" + sum_dem +
                ", per_area=" + per_area +
                '}';
    }

    public BigDecimal getArea() {
        return area;
    }

    public void setArea(BigDecimal area) {
        this.area = area;
    }

    public BigDecimal getCount() {
        return count;
    }

    public void setCount(BigDecimal count) {
        this.count = count;
    }

    public BigDecimal getSum_dem() {
        return sum_dem;
    }

    public void setSum_dem(BigDecimal sum_dem) {
        this.sum_dem = sum_dem;
    }
}
