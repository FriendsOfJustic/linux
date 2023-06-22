package com.rsgisai.geohazard.data.controller.advice;

import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.exception.BusinessException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class GlobalBusinessExceptionHandler {
    @ExceptionHandler({BusinessException.class})
    public R<BusinessException> handle(BusinessException e) {
        return R.<BusinessException>fail(e.getMessage()).put("exception", e);
    }

    @ExceptionHandler({Exception.class})
    public R<?> handle(Exception e) {
        return R.fail(e.getMessage()).put("exception", e);
    }

}
