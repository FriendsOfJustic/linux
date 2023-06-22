package com.example.sys.vo;


//用于前后端数据的格式统一

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class resultType<T> {
    private Integer num;
    private String message;
    private  T data;
}
