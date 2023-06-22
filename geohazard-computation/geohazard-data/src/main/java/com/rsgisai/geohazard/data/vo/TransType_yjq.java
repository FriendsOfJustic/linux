package com.rsgisai.geohazard.data.vo;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


//给前端传入研究区数据
@Data
@NoArgsConstructor
@AllArgsConstructor
public class TransType_yjq {
    private String yjq_name;
    private Integer yjq_year;
    private Integer yjq_month;
    private String yjq_format;
    private  String yjq_region;
    private String yjq_subsystem;
}
