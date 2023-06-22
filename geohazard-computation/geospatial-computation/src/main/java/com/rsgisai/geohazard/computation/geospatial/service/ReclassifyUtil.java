package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.entity.RasterStats;

import java.util.ArrayList;

public class ReclassifyUtil {

    public static String generateReclassexpr(int outNumClass, double min, double max) {

        double range = max - min;
        double delta = range / outNumClass;// 分类间隔

        double leftMost = min - 1;
        double rightMost = max + 1;
        ArrayList<String> maps = new ArrayList<>(outNumClass);

        for (int i = 0; i < outNumClass; i++) {
            double left = i == 0 ? leftMost : (min + i * delta);
            double right = i == (outNumClass - 1) ? rightMost : min + (i + 1) * delta;// 确保相邻区间的 left-right 相等
            int I = i + 1;
            maps.add(String.format("[%f-%f):%d", left, right, I));
        }
        return String.join(", ", maps);
    }


    /**
     * 原始栅格里，坡向范围 [0, 360) 和 -1 表示平面没有坡向
     * 重分类之后，因为输出的栅格是无符号整型，所以 0 表示 Nodata，1-(n-1) 表示普通坡向，n 表示没有坡向的平面
     *
     * @param n 分类个数
     * @return PostGIS 的 ST_Reclass 函数的 reclassexpr 参数，表示重分类规则
     */
    public static String generateAspectReclassexpr(int n) {
        int min = 0;
        int max = 360;
        int range = 360;
        ArrayList<String> roles = new ArrayList<>(n);

        // 添加 无坡向
        roles.add("[-1-0):" + n);// 注意因为输出的栅格是无符号的，所以无坡向不能用-1表示，应该使用正整数表示

        int numberOfAspect = n - 1;// 分为 n 类，有 n-1 个坡向，-1 表示没有坡向的平面
        int delta = range / numberOfAspect;// 分类间隔
        for (int i = 0; i < numberOfAspect; i++) {// 注意总共 n 个类别，这里要减一
            int left = (min + i * delta);
            int right = (min + (i + 1) * delta);// 确保相邻区间的 left-right 相等
            int I = i + 1;
            if (i != numberOfAspect - 1) {
                roles.add(String.format("[%d-%d):%d", left, right, I));
            } else {
                roles.add(String.format("[%d-%d]:%d", left, max, I));
            }
        }
        return String.join(", ", roles);
    }

}
