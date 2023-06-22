package com.example.sys.service.impl;

import com.example.sys.geoserver.GeoserverRestManager;
import com.example.sys.mapper.SusAlgorithmMapper;
import com.example.sys.service.SusAlgorithmService;
import com.rsgisai.geohazard.system.common.config.GeohazardConfig;

import org.postgresql.util.PSQLException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;


@Service
public class SusAlgorithmServiceImpl implements SusAlgorithmService {


    @Autowired
    SusAlgorithmMapper susAlgorithmMapper;

    @Autowired
    private GeoserverRestManager geoserverManager;


    // 1  myrast插入错误
    @Override
    public Integer SusAlgorithm(Integer classnumber[]) throws IOException, PSQLException  {
        //要处理的tif的数量
        Integer NumOfTif=7;
        //开始先删除表
        susAlgorithmMapper.deleteAll();

        //插入中间结果 myrast
        susAlgorithmMapper.insertMidResult();


        //判断myrast表中数据的正确性
        Integer ret=susAlgorithmMapper.selectMidResultCount();
        if(ret==NumOfTif)
            System.out.println("myrast插入成功");
        else
        {
            System.out.println("myrast插入失败");
        }


        //对7张tif文件进行重分类，并插入新的表chain_sus_reclass
        for(Integer i=0;i<NumOfTif;i++)
        {
//            System.out.println("第"+(i+1)+"个开始插入");
//            System.out.println(Reclass(classnumber[i],i+1));
            susAlgorithmMapper.insertReclass(Reclass(classnumber[i],i+1),i+1);
        }

        //检查chain_sus_reclass是否插入成功
        ret=susAlgorithmMapper.selectReclassCount();
        if(ret==NumOfTif)
            System.out.println("reclass插入成功");
        else
        {
            System.out.println("reclass插入失败");
            return 2;
        }

        //查询灾害点的数量——TODO
        Integer numOfRiskPoint=susAlgorithmMapper.selectRiskPointCount();
        System.out.println("查询灾害点的数量");

        //计算 灾害点的占比
        for(Integer i=0;i<NumOfTif;i++)    // i 代表的是 tif 的编号
        {
            System.out.println("开始第"+(i+1)+"个图像的处理");
            //查询id=i+1栅格所有像原的数量
            Integer numOfAllPoint=susAlgorithmMapper.selectAllCount(i+1);
            System.out.println("查询所有点的数量 " + numOfAllPoint);

            //灾害点范围内的比值
            System.out.println("开辟空间"+classnumber[i]);
            Double[] RP=new Double[classnumber[i]];
            Integer[] RPCount=new Integer[classnumber[i]];

            for (int n=0;n<RP.length;n++)
                RPCount[n]=0;
            List<Integer> RiskPointArray = susAlgorithmMapper.selectRiskPointCountPerClass(i+1);

            //得到每个分段的灾害点的数量
            for (int n=0;n<RiskPointArray.size();n++) {
                RPCount[RiskPointArray.get(n)-1]++;
            }

            for(int n=0;n<classnumber[i];n++)
            {
                RP[n]=(double)RPCount[n]/numOfRiskPoint;
                System.out.println(RP[n]);
            }



//            for(Integer j=0;j<classnumber[i];j++)
//            {
//                double tmp1=susAlgorithmMapper.selectClass(i + 1, j + 1);
//                double tmp2=numOfRiskPoint;
//                System.out.println("处理"+tmp1+"   "+tmp2);
//                //TODO
//                RP[j]=tmp1/tmp2;
//            }
//            System.out.println("RP"+i);
//           for(Integer j=0;j<classnumber[i];j++)
//               System.out.println(RP[j]);



           //所有像原内的比值
            List<Integer> SP_value=susAlgorithmMapper.selectTifEachBandValue(i+1);
            List<Integer> SP_count=susAlgorithmMapper.selectTifEachBandCount(i+1);
            Double[] SP=new Double[classnumber[i]];


            for(Integer j=0;j<classnumber[i];j++)
            {
                SP[j]=0.0;
            }


            for(Integer j=0;j<SP_count.size();j++)
            {
                SP[SP_value.get(j)-1]=(double)SP_count.get(j)/ (double)numOfAllPoint;
            }


            System.out.println("SP " + i);

            for (Double e:SP
            ) {
                System.out.println(e);
            }



            List<Double> info=new ArrayList<>();
            for(Integer j=0;j<classnumber[i];j++)
            {
                if(SP[j]==0 || RP[j]==0 )
                info.add(0.001);
                else
                    info.add(Math.log(SP[j]/RP[j])/Math.log(Math.E)*1000);
            }

            System.out.println("result:"+i+"Sp的数量"+classnumber[i]+"RP数量"+classnumber[i]);
            for (double e:info
                 ) {
                System.out.println(e);
            }
           //重新分类
           try {
               susAlgorithmMapper.insertRedefine(ReDefine(classnumber[i],info),i+1);
           }
           catch (PSQLException e)
           {
               System.out.println("sssssssssssssssssss");
               throw e;
           }
        }

        //得到结果
        susAlgorithmMapper.selectResultTif();

        System.out.println("开始上传图层");
        byte[]  rast=susAlgorithmMapper.selectResultImage(15).getTif();

        String layerName="pieceOfshit";

        // publish
        InputStream inputStream = new ByteArrayInputStream(rast);
        geoserverManager.uploadGeoTiff(
                GeohazardConfig.WORKSPACE,// 项目默认工作空间，不需要改变
                layerName,// 自定义
                inputStream// 固定写法
        );
        inputStream.close();// 固定写法


        geoserverManager.setLayerStyle( GeohazardConfig.WORKSPACE,layerName,"chain_sus");

        System.out.println("结束");
        return 0;
    }


    //输出符合st_reclass要求的参数
    @Override
    public String Reclass(Integer num, Integer id) {

        Double max=susAlgorithmMapper.selectMax(id);
        Double min=susAlgorithmMapper.selectMin(id);

        StringBuilder result=new StringBuilder();
        double increase=(max-min)/num;
        System.out.println(increase);
        double start=min;
        Integer i=0;
        for( i=0;i<num-1;i++)
        {

            double end=start+increase;
            DecimalFormat df1 = new DecimalFormat("#.##");
            String  str1 = df1.format(start);
            String str2=df1.format(end);
            String cur="["+str1+"-"+str2+")"+":"+(i+1);
            result.append(cur).append(',');
            start=end;
        }
        double end=start+increase;
        DecimalFormat df1 = new DecimalFormat("#.##");
        String  str1 = df1.format(start);
        String str2=df1.format(end);
        String cur="["+str1+"-"+str2+"]"+":"+(i+1);
        result.append(cur);

        return result.toString();
    }


    @Override
    public String ReDefine(Integer num,List<Double> info) {

        Integer max=num;
        Integer min=1;

        StringBuilder result=new StringBuilder();

        for( Integer i=0;i<num;i++)
        {
            String cur="["+(i+1)+"-"+(i+1)+"]"+":"+info.get(i);
            result.append(cur).append(',');
        }

        System.out.println(result.toString());
        return result.toString();
    }
}
