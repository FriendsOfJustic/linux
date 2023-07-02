package com.example.geohazardmain.client;
import com.example.geohazardmain.Transfer.R;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

@FeignClient("auth-service")// 注册在Eureka的里面的服务的名称  & 也可以写成绝对的URL
public interface AuthClient {
    @GetMapping("/auth-service/auth/public_key")  // IP:PORT(自动拼接) + *Mapping()
    R<String> publicKey();   //自动反序列化 注意entity！！！！
}
