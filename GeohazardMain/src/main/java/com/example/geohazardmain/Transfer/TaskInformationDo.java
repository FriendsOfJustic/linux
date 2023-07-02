/**
 * Copyright © 2020
 * 
 * @Package: com.agrs.message.entity
 * @author: Administrator
 * @date: 2020年7月29日 下午2:16:01
 */
package com.example.geohazardmain.Transfer;

//getmessage的结构体，这个结构体是用来向包一的结构体轮询是否有任务


import java.io.Serializable;
import java.util.Map;
import java.util.Set;

/**
 * @ClassName: TaskInformationDo
 * @Description: MQ消息实体对象
 * @author: cxg
 * @date: 2020年7月29日 下午2:16:01
 */
public class TaskInformationDo implements Serializable {

    /**
     * 消息唯一ID
     */
    public String uniqueID;
    /**
     * 操作类型对应的接口名称
     */
    public String interfaceName;
    /**
     * 消息队列名称
     */
    public String queueName;
    /**
     * 调用者
     */
    public String originatorAddress;
    /**
     * 执行者
     */
    public String recipientAddress;
    /**
     * 消息创建时间
     */
    public String creationTime;

    /**
     * 接口执行参数
     */
    private Map<String, Object> content;

    public Map<String, Object> getContent() {
        return content;
    }

    public void setContent(Map<String, Object> content) {
        this.content = content;
    }

    public String getUniqueID() {
        return uniqueID;
    }

    public void setUniqueID(String uniqueID) {
        this.uniqueID = uniqueID;
    }

    public String getInterfaceName() {
        return interfaceName;
    }

    public void setInterfaceName(String interfaceName) {
        this.interfaceName = interfaceName;
    }

    public String getQueueName() {
        return queueName;
    }

    public void setQueueName(String queueName) {
        this.queueName = queueName;
    }

    public String getOriginatorAddress() {
        return originatorAddress;
    }

    public void setOriginatorAddress(String originatorAddress) {
        this.originatorAddress = originatorAddress;
    }

    public String getRecipientAddress() {
        return recipientAddress;
    }

    public void setRecipientAddress(String recipientAddress) {
        this.recipientAddress = recipientAddress;
    }

    public String getCreationTime() {
        return creationTime;
    }

    public void setCreationTime(String creationTime) {
        this.creationTime = creationTime;
    }


}
