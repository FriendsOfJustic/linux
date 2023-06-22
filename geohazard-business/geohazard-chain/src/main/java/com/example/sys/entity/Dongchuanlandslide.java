package com.example.sys.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.math.BigDecimal;
import java.math.BigInteger;

/**
 * <p>
 * 
 * </p>
 *
 * @author sht
 * @since 2023-04-17
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Dongchuanlandslide implements Serializable {
    //滑坡体体积
    @TableField(value = "volume")
    private double volume;
    //滑坡体面积
    private  double area;
    // 坡顶高程
    private double h1;
    // 坡底高程
    private  double h2;
    public double getVolume() {
        return volume;
    }
    public void setVolume(double volume) {
        this.volume = volume;
    }
    public double getArea() {
        return area;
    }
    public void setArea(double area) {
        this.area = area;
    }
    public double getH1() {
        return h1;
    }
    public void setH1(double h1) {
        this.h1 = h1;
    }
    public double getH2() {
        return h2;
    }
    public void setH2(double h2) {
        this.h2 = h2;
    }
}
