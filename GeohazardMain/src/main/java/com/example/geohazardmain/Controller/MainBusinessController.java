package com.example.geohazardmain.Controller;


import com.example.geohazardmain.Service.GeohazardChainService;
import com.example.geohazardmain.Transfer.MessageFromRerssilFront;
import com.example.geohazardmain.Transfer.R;
import com.example.geohazardmain.Transfer.StatusToFront;
import com.example.geohazardmain.client.GeohazardChainClient;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;
import org.postgresql.util.PSQLException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.ReentrantLock;


@RestController
@RequestMapping("/main")
public class MainBusinessController {
    //读者、写者问题不需要加锁
    public Map<String, StatusToFront> RunningTask=new HashMap<String, StatusToFront>();


    //灾害链的锁
    private ReentrantLock GeohazardChainLock = new ReentrantLock();


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
        public  StatusToFront msg;
        @Override
        public void run() {
            if(msg.getMessageFromRerssilFront().getWhichSys()=="risk-level")
            {
                //执行风险等级的整合逻辑
            }
            else if(msg.getMessageFromRerssilFront().getWhichSys().equals("geohazard-chain"))
            {

                //执行灾害链的整合逻辑
                try {
                    GeohazardChainLock.lock();
                   System.out.println("我拿到锁了！！！！");
                    geohazardChainService.PollingLogic();  //后端整合逻辑
                    GeohazardChainLock.unlock();
                } catch (IOException e) {
                    //抛出异常之后必须把锁交出来，否则会造成死锁
                    GeohazardChainLock.unlock();
                    throw new RuntimeException(e);
                } catch (PSQLException e) {
                    //抛出异常之后必须把锁交出来，否则会造成死锁
                    GeohazardChainLock.unlock();
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
        //设置任务状态 - 刚开始是等待，无法保证立即执行
        RunningTask.put(msg.getTaskID(),new StatusToFront("waiting",msg));

        System.out.println(msg.toString());

        System.out.println("现有任务如下");
        // 使用foreach循环遍历
        for (Map.Entry<String, StatusToFront> entry : RunningTask.entrySet()) {
            String key = entry.getKey();
            StatusToFront value = entry.getValue();
            System.out.println(key + " : " + value.toString());
        }

        //分离已给线程执行任务
        MyThread myThread=new MyThread(new StatusToFront("waiting",msg));
        myThread.setDaemon(true);   //线程分离，主线程立刻返回响应给前端，子线程执行整合逻辑
        myThread.start();



        //分离一个线程返回给前端——后端已经开始准备执行任务
        if(msg.getWhichSys()=="risk-level")
        {
            //执行风险等级的整合逻辑
            return R.ok(msg.getTaskID()+" waiting！");
        }
        else if(msg.getWhichSys().equals("geohazard-chain"))
        {
            //执行灾害链的整合逻辑
            return R.ok(msg.getTaskID()+" waiting！");
        }
        else
        {
            //错误的请求
          return R.ok("Bad Request");
        }
    }

}
