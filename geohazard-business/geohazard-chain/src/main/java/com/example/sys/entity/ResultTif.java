package com.example.sys.entity;


import com.baomidou.mybatisplus.annotation.TableField;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ResultTif {

    @TableField(value = "tif")
    private byte[] tif;


    public byte[] getTif() {
        return tif;
    }

    public void setTif(byte[] tif) {
        this.tif = tif;
    }
}

