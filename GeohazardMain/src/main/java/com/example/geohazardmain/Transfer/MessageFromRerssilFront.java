package com.example.geohazardmain.Transfer;


import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class MessageFromRerssilFront {
    @JsonProperty("WhichSys")
    private String WhichSys;    //要执行哪个子系统的后端

    @JsonProperty("TaskID")
    private String TaskID;      //用来唯一标识任务的ID

    @JsonProperty("Content")
    private Object Content;       //前端传过来的参数



    @Override
    public String toString() {
        return "MessageFromRerssilFront{" +
                "WhichSys='" + WhichSys + '\'' +
                ", TaskID='" + TaskID + '\'' +
                ", Content=" + Content +
                '}';
    }

    public String getWhichSys() {
        return WhichSys;
    }

    public void setWhichSys(String whichSys) {
        WhichSys = whichSys;
    }

    public String getTaskID() {
        return TaskID;
    }

    public void setTaskID(String taskID) {
        TaskID = taskID;
    }

    public Object getContent() {
        return Content;
    }

    public void setContent(Object content) {
        Content = content;
    }
}
