package com.example.geohazardmain.Transfer;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

//向前端返回的状态码
@Data
@NoArgsConstructor
@AllArgsConstructor
public class StatusToFront {

    private  String status;   //状态码

    private MessageFromRerssilFront messageFromRerssilFront;   //前段传过来的ID


    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public MessageFromRerssilFront getMessageFromRerssilFront() {
        return messageFromRerssilFront;
    }

    public void setMessageFromRerssilFront(MessageFromRerssilFront messageFromRerssilFront) {
        this.messageFromRerssilFront = messageFromRerssilFront;
    }

    @Override
    public String toString() {
        return "SatusToFront{" +
                "status='" + status + '\'' +
                ", messageFromRerssilFront=" + messageFromRerssilFront +
                '}';
    }
}
