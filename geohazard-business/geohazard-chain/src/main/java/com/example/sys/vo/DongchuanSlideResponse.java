package com.example.sys.vo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class DongchuanSlideResponse {


    //滑坡体垂直落差
    private double Height;
    //滑坡体厚度
    private double LandSlideThickness;

    //计算最大摩擦系数
    private double f;

    //计算最大滑距
    private  double LandslideDis;

    //河坝高度
    private  double DamHeight;

    //是否能够堵江
    private  boolean ret;

    public double getHeight() {
        return Height;
    }

    public void setHeight(double height) {
        Height = height;
    }

    public double getLandSlideThickness() {
        return LandSlideThickness;
    }

    public void setLandSlideThickness(double landSlideThickness) {
        LandSlideThickness = landSlideThickness;
    }

    public double getF() {
        return f;
    }

    public void setF(double f) {
        this.f = f;
    }

    public double getLandslideDis() {
        return LandslideDis;
    }

    public void setLandslideDis(double landslideDis) {
        LandslideDis = landslideDis;
    }

    public double getDamHeight() {
        return DamHeight;
    }

    public void setDamHeight(double damHeight) {
        DamHeight = damHeight;
    }

    public boolean isRet() {
        return ret;
    }

    public void setRet(boolean ret) {
        this.ret = ret;
    }

    @Override
    public String toString() {
        return "DongchuanSlideResponse{" +
                "Height=" + Height +
                ", LandSlideThickness=" + LandSlideThickness +
                ", f=" + f +
                ", LandslideDis=" + LandslideDis +
                ", DamHeight=" + DamHeight +
                ", ret=" + ret +
                '}';
    }
}
