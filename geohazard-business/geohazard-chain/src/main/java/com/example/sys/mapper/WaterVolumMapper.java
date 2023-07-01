package com.example.sys.mapper;
import com.example.sys.entity.ResultTif;
import com.example.sys.entity.WaterVolume;
import org.apache.ibatis.annotations.Mapper;
import org.bouncycastle.util.test.FixedSecureRandom;

import java.math.BigDecimal;
import java.math.BigInteger;

@Mapper
public interface WaterVolumMapper  {

    ResultTif getResult();
    void OutPut();
    //计算水域矢量的面积
    WaterVolume selectArea();



    //计算tif文件的像素数量
    WaterVolume selectNum();

    //直接计算第二个参数的值
    BigDecimal selectR2();
}
