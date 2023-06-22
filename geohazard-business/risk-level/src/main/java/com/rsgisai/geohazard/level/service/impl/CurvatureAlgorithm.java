package com.rsgisai.geohazard.level.service.impl;

import com.rsgisai.geohazard.level.service.ReclassifyUtil;

import java.util.ArrayList;

public class CurvatureAlgorithm {
    public String generateReclassexpr(int n, double min, double max) {
//        String s = ReclassifyUtil.generateReclassexpr(numberClasses, min, max);
        min = min - 1;
        max = max + 1;
        double range = max - min;
        ArrayList<String> roles = new ArrayList<>(n);

        double delta = range / n;// 分类间隔
        for (int i = 0; i < n; i++) {// 注意总共 n 个类别，这里要减一
            double left = min + i * delta;
            double right = min + (i + 1) * delta;// 确保相邻区间的 left-right 相等
            int I = i + 1;
            roles.add(String.format("[%f-%f):%d", left, right, I));
        }
        return String.join(", ", roles);
    }
}
