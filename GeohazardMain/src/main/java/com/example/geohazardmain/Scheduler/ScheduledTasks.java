package com.example.geohazardmain.Scheduler;

import java.text.SimpleDateFormat;
import java.util.Date;

import com.example.geohazardmain.client.AuthClient;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

@Component
public class ScheduledTasks {
    @Autowired
    AuthClient authClient;
    private static final Logger log = LoggerFactory.getLogger(ScheduledTasks.class);

    private static final SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");

    @Scheduled(fixedRate = 1000)
    public void reportCurrentTime() {
        //实现 轮询的逻辑

        //1.GetMessage那消息做判断  阻塞非阻塞？
        //2.业务逻辑
        //3.SendMessage 返回到包一指定的结果队列
        //authClient.publicKey();
        log.info("The time is now {}", dateFormat.format(new Date()));
    }
}