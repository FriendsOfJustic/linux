package com.example.sys.entity;



import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ResultTif {

    private byte[] tiff;


    public byte[] getTif() {
        return tiff;
    }

    public void setTif(byte[] tif) {
        this.tiff = tif;
    }
}

