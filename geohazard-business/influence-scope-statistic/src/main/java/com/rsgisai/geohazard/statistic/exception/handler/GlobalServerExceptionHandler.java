package com.rsgisai.geohazard.statistic.exception.handler;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import org.springframework.web.method.annotation.MethodArgumentTypeMismatchException;

@RestControllerAdvice
public class GlobalServerExceptionHandler {
    /**
     * 遇到的坑：直接返回 R<MethodArgumentTypeMismatchException> ，然后前端没法收到预期的 R ，而是什么消息也没有
     * 原因：后面Debug 发现原来是因为 MethodArgumentTypeMismatchException 没办法序列化，从而这个 handler 继续抛异常
     * 一些信息：MethodArgumentTypeMismatchException 本身也是带了注解 @SuppressWarnings("serial") ，这个注解说明当在可序列化的类上缺少 serialVersionUID 定义时的警告
     *
     * 第二个坑，注意这里的 MethodArgumentTypeMismatchException 是在 org.springframework.web.bind.annotation 包下的
     * 不是 org.springframework.messaging.handler.annotation.support 包下面的，还是要细心一点啊！！！
     */
    @ExceptionHandler({MethodArgumentTypeMismatchException.class})
    public R<String> handle(MethodArgumentTypeMismatchException e) {
        return R.<String>fail("请求参数格式不正确，请检查").data(e.getCause().getMessage());
    }
}

