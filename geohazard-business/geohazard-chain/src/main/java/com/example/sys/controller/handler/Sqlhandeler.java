package com.example.sys.controller.handler;


import com.rsgisai.geohazard.system.common.R;
import org.postgresql.util.PSQLException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import java.io.IOException;

@RestControllerAdvice
public class Sqlhandeler {
//    @ExceptionHandler({PSQLException.class})
//    public R<PSQLException > handle(PSQLException  e) {
//        return R.<PSQLException >fail(e.getMessage()).put("sqlexception",e);
//    }


    @ExceptionHandler({IOException.class})
    public R<PSQLException > handleIo(PSQLException  e) {
        return R.<PSQLException >fail(e.getMessage()).put("IOexception",e);
    }

}
