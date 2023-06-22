package com.rsgisai.geohazard.level.service;

import java.util.ArrayList;

public class ReclassifyUtil {

    public static String generateReclassexpr(int n,double min,double max) {
        min=min-1;max=max+1;
        double range=max-min;
        ArrayList<String> roles = new ArrayList<>(n);

        double delta = range / n;// 分类间隔
        for (int i = 0; i < n ; i++) {// 注意总共 n 个类别，这里要减一
            int left = (int) (min + i * delta);
            int right = (int) (min + (i + 1) * delta);// 确保相邻区间的 left-right 相等
            int I = i + 1;
            roles.add(String.format("[%d-%d):%d", left, right, I));
        }
        return String.join(", ", roles);
    }
}
