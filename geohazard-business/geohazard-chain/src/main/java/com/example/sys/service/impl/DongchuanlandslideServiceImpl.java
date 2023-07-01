package com.example.sys.service.impl;

import com.example.sys.entity.Dongchuanlandslide;
import com.example.sys.geoserver.GeoserverRestManager;
import com.example.sys.mapper.DongchuanlandslideMapper;
import com.example.sys.service.IDongchuanlandslideService;

import com.example.sys.transfer.BlockRiver;
import com.example.sys.vo.DongchuanSlideResponse;
import com.rsgisai.geohazard.system.common.config.GeohazardConfig;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author sht
 * @since 2023-04-17
 */
@Service
public class DongchuanlandslideServiceImpl  implements IDongchuanlandslideService {


    @Autowired
    DongchuanlandslideMapper dongchuanlandslideMapper;
    @Autowired
    private GeoserverRestManager geoserverManager;


    //算对数的函数
    public static double log(double value, double base) {
        return Math.log(value) / Math.log(base);
    }

    //版本被废弃
//    @Override
//    public DongchuanSlideResponse BlockRiverAlgorithm(String number, Double waterWidth, Double waterDepth, Double l1)  //l1为滑坡前缘到江对面的距离
//    {
//        System.out.println("2");
//        Dongchuanlandslide ret=dongchuanlandslideMapper.selectBynumber(number);
//
//        if(ret==null)
//        {
//           return null;
//        }
//
//        //滑坡体垂直落差
//        double Height=ret.getH1()- ret.getH2();
//
//
//        System.out.printf("滑坡体垂直落差：%f\n",Height);
//
//
//        //滑坡体厚度
//       double LandSlideThickness =ret.getVolume()/ret.getArea();
//
//
//        System.out.printf("滑坡体厚度：%f\n",LandSlideThickness);
//
//
//        //计算最大摩擦系数
//        double f=Math.pow(10,-0.15666*log(ret.getVolume(),10)+0.62219);
//
//        System.out.printf("最大摩擦系数：%f\n",f);
//
//        //计算最大滑距
//        double LandslideDis=Height/f;
//        System.out.printf("最大滑动距离：%f\n",LandslideDis);
//
//        //河坝高度
//        double DamHeight=(1-l1/LandslideDis)*(1+f)*LandSlideThickness+LandslideDis/waterWidth;
//        System.out.printf("河坝高度：%f\n",DamHeight);
//
//
//        //比较 河水深度 和 河坝高度
//        //ret1 为 true
//        boolean ret1=waterDepth>DamHeight?true:false;
//
//        //比较 河流宽度 和 最大滑动距离
//        boolean ret2=waterWidth>LandslideDis?true:false;
//
//
//
//
//
//        //返回true代表发生堵江   返回false代表没有堵江
//       boolean final_ret= ret1==false&&ret2==false?true:false;
//
//       return new DongchuanSlideResponse(Height,LandSlideThickness,f,LandslideDis,DamHeight,final_ret);
//
//
//
//    }


    //0.976+0.001*坡高-0.739*宽深比-0.003*河宽指数+0.68*不对称系数+0.049*平均坡度-0.268*剖面面积（KM^2）

    @Override
    public String BlockRiverAlgorithm(List<BlockRiver> para) throws IOException {



        List<Integer> Result=new ArrayList<>();

        for(Integer i=0;i<para.size();i++)
        {
            Double mid=0.976+0.001*para.get(i).getSlopeHeight()-0.739*para.get(i).getWithDepthRatio()
                    -0.003*para.get(i).getWithIndex()+0.68*para.get(i).getBuDuiChengRatio()+0.049*para.get(i).getAverageSlop()
                    -0.268*para.get(i).getArea();
            System.out.println(mid);
            Integer mid_result=0;
            if(mid>=0.8)
            {
                mid_result=5;
            }
            else if(mid<0.8 && mid>=0.6)
            {
                mid_result=4;
            }
            else if(mid<0.6 && mid>=0.4)
            {
                mid_result=3;
            }
            else
            {
                mid_result =2;
            }
            Result.add(mid_result);
        }
        deleteAllMidResult(Result.size());
        System.out.println("开始查询");
        System.out.println(para.size());
        for (Integer e: Result
             ) {
            System.out.println(e);
        }
        dongchuanlandslideMapper.CreateResultLayerData();

        for (int i=0;i<para.size();i++) {
            dongchuanlandslideMapper.InsertResultGeom(para.get(i).getId(),Result.get(i));
        }

        return  "BlockRiverRiskPoint";

//        dongchuanlandslideMapper.PrepareWork();
//        //获取到了
//        String tablename="tmp";
//
//
//        dongchuanlandslideMapper.LoopAssignment(tablename+"0",tablename+"0","Duhe_mid",para.get(0).getId(),Result.get(0));
//        Integer i=1;
//
//        while(i<Result.size())
//        {
//            dongchuanlandslideMapper.LoopAssignment(tablename+(i),tablename+i,tablename+(i-1),para.get(i).getId(),Result.get(i));
//            i++;
//        }
//        System.out.println("重分类完成");
//
//        System.out.println("开始上传图层");
//        byte[]  rast=dongchuanlandslideMapper.selectResultImage("tmp"+(Result.size()-1)).getTif();
//
//        String layerName="BlockRiver";
//
//        // publish
//        InputStream inputStream = new ByteArrayInputStream(rast);
//        geoserverManager.uploadGeoTiff(
//                GeohazardConfig.WORKSPACE,// 项目默认工作空间，不需要改变
//                layerName,// 自定义
//                inputStream// 固定写法
//        );
//        inputStream.close();// 固定写法
//
//
//        geoserverManager.setLayerStyle( GeohazardConfig.WORKSPACE,layerName,"BlockRiverStyle");
//        deleteAllMidResult(Result.size());
//        System.out.println("结束");


    }

    @Override
    public void deleteAllMidResult(Integer num)
    {
        dongchuanlandslideMapper.deleteLoop("Duhe_mid");
        for(Integer i=0;i<num;i++)
        {
            dongchuanlandslideMapper.deleteLoop("tmp"+i);
        }
    }


}
