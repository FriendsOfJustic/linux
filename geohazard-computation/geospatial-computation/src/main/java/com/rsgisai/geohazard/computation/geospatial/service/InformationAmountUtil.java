package com.rsgisai.geohazard.computation.geospatial.service;

import com.rsgisai.geohazard.computation.geospatial.dao.pgsql.InformationAmountDao;
import com.rsgisai.geohazard.computation.geospatial.entity.InformationAmount;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * @author tfh, created at 2023-03-12 3:38 PM
 */
public class InformationAmountUtil {

    public static String generateXxlMappingExpression(List<InformationAmount> xxlList, int numberClasses) {
        ArrayList<String> mappingList = new ArrayList<>();
        mappingList.add("0:7654321");

        // map to no data, 重分类里使用的是0表示nodata，而信息量里也可能出现0，所以需要将nodata换成其他数值
        // 信息量一般不超过正负10，所以我们使用 7654321 表示nodata

        HashMap<Integer, Double> map = new HashMap<>();
        for (InformationAmount xxl : xxlList) {
            map.put(xxl.getLevel(), xxl.getInformationAmount());
        }

        for (int i = 0; i < numberClasses; i++) {
            int I = i + 1;
            mappingList.add(String.format("%d:%f", I, map.getOrDefault(I, 0D)));
        }
        return String.join(", ", mappingList);
    }
}
