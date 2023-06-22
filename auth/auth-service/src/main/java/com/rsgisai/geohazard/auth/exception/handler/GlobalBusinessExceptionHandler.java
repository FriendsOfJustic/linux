package com.rsgisai.geohazard.auth.exception.handler;

import com.rsgisai.geohazard.auth.exception.BusinessException;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class GlobalBusinessExceptionHandler {
    @ExceptionHandler({BusinessException.class})
    public R<BusinessException> handle(BusinessException e) {
        return R.<BusinessException>fail(e.getMessage()).data(e);
    }

}
