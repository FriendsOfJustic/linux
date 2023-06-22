package com.example.sys.transfer;


//public  resultType<Boolean> fun(@RequestParam("number")String number,@RequestParam("width")Double with,@RequestParam("depth") Double depth,@RequestParam("l1")Double l1)
//    {

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;



//用于和前端交互的数据 RequestBody
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ParamData implements Serializable {

    private  String  dhwxx_number;
    private  Double dhwxx_with ;
    private  Double dhwxx_depth;
    private  Double dhwxx_l1;

    @Override
    public String toString() {
        return "ParamData{" +
                "dhwxx_number='" + dhwxx_number + '\'' +
                ", dhwxx_with=" + dhwxx_with +
                ", dhwxx_depth=" + dhwxx_depth +
                ", dhwxx_l1=" + dhwxx_l1 +
                '}';
    }

    public String getDhwxx_number() {
        return dhwxx_number;
    }

    public void setDhwxx_number(String dhwxx_number) {
        this.dhwxx_number = dhwxx_number;
    }

    public Double getDhwxx_with() {
        return dhwxx_with;
    }

    public void setDhwxx_with(Double dhwxx_with) {
        this.dhwxx_with = dhwxx_with;
    }

    public Double getDhwxx_l1() {
        return dhwxx_l1;
    }

    public void setDhwxx_l1(Double dhwxx_l1) {
        this.dhwxx_l1 = dhwxx_l1;
    }

    public Double getDhwxx_depth() {
        return dhwxx_depth;
    }

    public void setDhwxx_depth(Double dhwxx_depth) {
        this.dhwxx_depth = dhwxx_depth;
    }
}
