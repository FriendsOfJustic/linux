package com.rsgisai.geohazard.statistic.exception.handler;

import com.rsgisai.geohazard.statistic.exception.BusinessException;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class GlobalBusinessExceptionHandler {
    /**
     * 原理：
     * '@ExceptionHandler' 注解的方法会交由 ExceptionHandlerExceptionResolver 进行调用
     * 而 ExceptionHandlerExceptionResolver 则会由 HandlerExceptionResolverComposite 进行管理、调用
     */
    @ExceptionHandler({BusinessException.class})
    public R<BusinessException> handle(BusinessException e) {
        return R.<BusinessException>fail(e.getMessage()).data(e);
    }
}
