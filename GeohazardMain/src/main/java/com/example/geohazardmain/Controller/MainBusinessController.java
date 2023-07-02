package com.example.geohazardmain.Controller;


import com.example.geohazardmain.Lock.GeohazardChainLock;
import com.example.geohazardmain.Service.GeohazardChainService;
import com.example.geohazardmain.Transfer.MessageFromRerssilFront;
import com.example.geohazardmain.Transfer.R;
import com.example.geohazardmain.client.GeohazardChainClient;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;
import org.postgresql.util.PSQLException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


@RestController
@RequestMapping("/main")
public class MainBusinessController {

    public Map<String,String> RunningTask=new HashMap<String,String>();

    //private ReentrantLock GeohazardChainLock = new ReentrantLock();

    @Autowired
    GeohazardChainLock geohazardChainLock;

    @Autowired
    GeohazardChainClient geohazardChainClient;

    @Autowired
    GeohazardChainService geohazardChainService;

    @GetMapping("/GetSatus")
    public R<String> SelectSatus()
    {
        return null;
    }
    @NoArgsConstructor
    @AllArgsConstructor
    class MyThread extends Thread{
        public MessageFromRerssilFront msg;
        @Override
        public void run() {
            if(msg.getWhichSys()=="risk-level")
            {
                //执行风险等级的整合逻辑
            }
            else if(msg.getWhichSys().equals("geohazard-chain"))
            {

                //执行灾害链的整合逻辑
                try {
                   geohazardChainLock.lock.lock();
                   System.out.println("我拿到锁了！！！！");
                    geohazardChainService.PollingLogic();
                    geohazardChainLock.lock.unlock();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                } catch (PSQLException e) {
                    throw new RuntimeException(e);
                }
            }
            else
            {
                //错误的请求
               System.out.println("Badrequest");
            }
        }

    }

    @PostMapping("/TaskSatrt")
    public R<String> MainController(@RequestBody MessageFromRerssilFront msg) throws PSQLException, IOException {
        System.out.println(msg.toString());

        //不是并发执行的需要建立一个队列等待 -TODO

        System.out.println("现有任务如下");
        // 使用foreach循环遍历
        for (Map.Entry<String, String> entry : RunningTask.entrySet()) {
            String key = entry.getKey();
            String value = entry.getValue();
            System.out.println(key + " : " + value);
        }
        //设置任务状态
        RunningTask.put(msg.getTaskID(),"begin");


        //分离已给线程执行任务
        MyThread myThread=new MyThread(msg);
        myThread.setDaemon(true);
        myThread.start();



        //分离一个线程返回给前端——后端已经开始执行任务
        if(msg.getWhichSys()=="risk-level")
        {
            //执行风险等级的整合逻辑
            return R.ok(msg.getTaskID()+" begin!");
        }
        else if(msg.getWhichSys().equals("geohazard-chain"))
        {
            //执行灾害链的整合逻辑
            return R.ok(msg.getTaskID()+" begin!");
        }
        else
        {
            //错误的请求
          return R.ok("Bad Request");
        }
    }

}
