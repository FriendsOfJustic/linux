package com.example.sys.service.impl;


import com.example.sys.entity.CarrierLossCaculatePerFloodArea;
import com.example.sys.mapper.CarrierRiskAssessmentMapper;
import com.example.sys.service.CarrierRiskAssessmentService;
import org.apache.ibatis.annotations.Case;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class CarrierRiskAssessmentServiceImpl implements CarrierRiskAssessmentService {


    @Autowired
    CarrierRiskAssessmentMapper carrierRiskAssessmentMapper;

    @Override
    public List<CarrierLossCaculatePerFloodArea> CarrierRiskAssessmentAlgorithmn()
    {
        List<CarrierLossCaculatePerFloodArea> Result=new ArrayList<>();
        List<Integer> FloodAreaId=carrierRiskAssessmentMapper.selectFloodAreaId();
        for(Integer i=0;i<FloodAreaId.size();i++)
        {
            System.out.println("开始查询洪水id为"+FloodAreaId.get(i));
            carrierRiskAssessmentMapper.CreateMidResult(FloodAreaId.get(i));
            List<Double> area = carrierRiskAssessmentMapper.MidResultArea();
            List<Integer> type=carrierRiskAssessmentMapper.MidResultType();

            CarrierLossCaculatePerFloodArea cur=new CarrierLossCaculatePerFloodArea();
            cur.LossArea=0.0;
            cur.LossMoney=0.0;
            cur.LossPeople=0;
            cur.FloodAreaId=FloodAreaId.get(i);

            for(Integer j=0;j<area.size();j++)
            {
                //cur.LossArea+=area.get(j);
                switch (type.get(j))
                {
                    case 11: //城区
                    {
                        cur.LossPeople+=15;
                        cur.LossMoney+=area.get(j)*8000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 12: //乡镇
                    {
                        cur.LossPeople+=8;
                        cur.LossMoney+=area.get(j)*2000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 13: //村
                    {
                        cur.LossPeople+=4;
                        cur.LossMoney+=area.get(j)*1000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 21: //采矿用地
                    {
                        cur.LossMoney+=area.get(j)*8000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 22:  //工业用地
                    {
                        cur.LossMoney+=area.get(j)*10000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 3:  //耕地
                    {
                        cur.LossMoney+=area.get(j)*200;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 4: //林草地
                    {
                        cur.LossMoney+=area.get(j)*150;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 51: //高速公路
                    {
                        cur.LossMoney+=area.get(j)*1000000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 52: //省级道路
                    {
                        cur.LossMoney+=area.get(j)*50000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 53: //县级道路
                    {
                        cur.LossMoney+=area.get(j)*10000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                    case 54: //乡级公路
                    {
                        cur.LossMoney+=area.get(j)*1000;
                        cur.LossArea+=area.get(j);
                        break;
                    }
                }

            }

            if(cur.LossPeople>=1000 || cur.LossMoney>=50000000)
                cur.RiskLevel=4;
            else if(  (cur.LossPeople>=100 &&cur.LossPeople<1000) || (cur.LossMoney>=10000000 &&cur.LossMoney<50000000))
                cur.RiskLevel=3;
            else if((cur.LossPeople>=10 && cur.LossPeople<=100) || (cur.LossMoney>=5000000 && cur.LossMoney<10000000))
                cur.RiskLevel=2;
            else
                cur.RiskLevel=1;
            Result.add(cur);
        }
        carrierRiskAssessmentMapper.CreateResultLayer();
        for (CarrierLossCaculatePerFloodArea e:Result
        ) {
            carrierRiskAssessmentMapper.InsertResultLayer(e.FloodAreaId,e.RiskLevel);
            System.out.println(e.toString());
        }
        System.out.println("结束");

        return Result;
    }
}
