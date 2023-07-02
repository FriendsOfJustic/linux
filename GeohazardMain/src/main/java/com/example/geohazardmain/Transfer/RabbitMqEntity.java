package com.example.geohazardmain.Transfer;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.UUID;


// 这个结构体是向包一的结果结构体返回结果
/**
 * @author surpassliang
 * @version 1.0
 * @date 2023/5/31
 */
public class RabbitMqEntity {

    private String uniqueID;
    private String queueName;
    private String interfaceName;
    private String originatorAddress;
    private String recipientAddress;
    private String creationTime;
    private Object content;

    public String getUniqueID() {
        return uniqueID;
    }

    public void setUniqueID(String uniqueID) {
        this.uniqueID = uniqueID;
    }

    public String getQueueName() {
        return queueName;
    }

    public void setQueueName(String queueName) {
        this.queueName = queueName;
    }

    public String getInterfaceName() {
        return interfaceName;
    }

    public void setInterfaceName(String interfaceName) {
        this.interfaceName = interfaceName;
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

    public Object getContent() {
        return content;
    }

    public void setContent(Object content) {
        this.content = content;
    }

//    public static RabbitMqEntity createRabbitMqEntity(String orginAddr,String recipAddr,String interfaceName,Object content){
//        RabbitMqEntity rabbitMqEntity = new RabbitMqEntity();
//        rabbitMqEntity.setContent(content);
//        rabbitMqEntity.setCreationTime(LocalDateTime.now().format(DateTimeFormatter.ofPattern(DateUtils.DATA_FORMAT)));
//        rabbitMqEntity.setInterfaceName(String.format("%s_%s_TO_%s",orginAddr,interfaceName,recipAddr));
//        rabbitMqEntity.setOriginatorAddress(orginAddr);
//        rabbitMqEntity.setRecipientAddress(recipAddr);
//        rabbitMqEntity.setQueueName(String.format("%s_TO_%s",orginAddr,recipAddr));
//        rabbitMqEntity.setUniqueID(UUID.randomUUID().toString());
//        return rabbitMqEntity;
//    }
}
