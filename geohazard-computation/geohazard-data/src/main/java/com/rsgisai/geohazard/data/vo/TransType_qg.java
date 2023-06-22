package com.rsgisai.geohazard.data.vo;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;



//向前端传输的全国数据
@Data
@NoArgsConstructor
@AllArgsConstructor
public class TransType_qg {
    private String qg_name;
    private Integer qg_year;
    private Integer qg_month;
    private String qg_format;
    private  String qg_region;
    private String qg_subsystem;
}
