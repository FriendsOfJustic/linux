package com.example.geohazardmain.client;


import org.springframework.cloud.openfeign.FeignClient;
//注意不要忘记 设置MainApplication的配置位dev 否则服务起不来

//向包一的消息队列请求消息

@FeignClient(name = "SendMessage",url = "http://10.0.5.169:8021/sendMessage")   //可以直接写成url绝对路径
public interface SendMessage {
}
