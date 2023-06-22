package com.example.sys.transfer;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class NumOfReclass implements Serializable {

    private  Integer numDem;
    private  Integer numSlop;
    private  Integer numAspect;
    private  Integer numCurvature;
    private  Integer numWater;
    private  Integer numRainFall;
    private  Integer numRock;

    @Override
    public String toString() {
        return "NumOfReclass{" +
                "numDem=" + numDem +
                ", numSlop=" + numSlop +
                ", numAspect=" + numAspect +
                ", numCurvature=" + numCurvature +
                ", numWater=" + numWater +
                ", numRainFall=" + numRainFall +
                ", numRock=" + numRock +
                '}';
    }
}
