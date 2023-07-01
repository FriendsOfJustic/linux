package com.example.sys.entity;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class CarrierLossCaculatePerFloodArea {

    @JsonProperty("lossMoney")
    public Double LossMoney;

    @JsonProperty("lossArea")
    public Double LossArea;

    @JsonProperty("lossPeople")
    public  Integer LossPeople;

    @JsonProperty("floodAreaId")
    public Integer FloodAreaId;


    @JsonProperty("riskLevel")
    public Integer RiskLevel;

    public Double getLossMoney() {
        return LossMoney;
    }

    public void setLossMoney(Double lossMoney) {
        LossMoney = lossMoney;
    }

    public Double getLossArea() {
        return LossArea;
    }

    public void setLossArea(Double lossArea) {
        LossArea = lossArea;
    }

    public Integer getLossPeople() {
        return LossPeople;
    }

    public void setLossPeople(Integer lossPeople) {
        LossPeople = lossPeople;
    }

    public Integer getFloodAreaId() {
        return FloodAreaId;
    }

    public void setFloodAreaId(Integer floodAreaId) {
        FloodAreaId = floodAreaId;
    }

    public Integer getRiskLevel() {
        return RiskLevel;
    }

    public void setRiskLevel(Integer riskLevel) {
        RiskLevel = riskLevel;
    }



    @Override
    public String toString() {
        return "CarrierLossCaculatePerFloodArea{" +
                "LossMoney=" + LossMoney +
                ", LossArea=" + LossArea +
                ", LossPeople=" + LossPeople +
                ", FloodAreaId=" + FloodAreaId +
                ", RiskLevel=" + RiskLevel +
                '}';
    }
}
