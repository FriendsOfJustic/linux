package com.rsgisai.geohazard.subsystem.exception.handler;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;

@RestControllerAdvice
public class GlobalExceptionHandler {
    @ExceptionHandler
    public R<String> handle(Exception e) throws IOException {
        StringWriter stringWriter = new StringWriter();
        PrintWriter printWriter = new PrintWriter(stringWriter);
        e.printStackTrace(printWriter);
        R<String> data = R.<String>fail(e.getMessage())
                .data(stringWriter.toString());
        printWriter.close();
        stringWriter.close();
        return data;
    }

}
