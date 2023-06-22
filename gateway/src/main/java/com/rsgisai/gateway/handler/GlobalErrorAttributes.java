package com.rsgisai.gateway.handler;

import com.rsgisai.geohazard.system.common.R;
import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.web.error.ErrorAttributeOptions;
import org.springframework.boot.web.reactive.error.DefaultErrorAttributes;
import org.springframework.core.annotation.MergedAnnotation;
import org.springframework.core.annotation.MergedAnnotations;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.reactive.function.server.ServerRequest;
import org.springframework.web.server.ResponseStatusException;

import java.util.Map;

import static org.springframework.http.HttpStatus.INTERNAL_SERVER_ERROR;

@Component
@Slf4j
public class GlobalErrorAttributes extends DefaultErrorAttributes {


    public GlobalErrorAttributes() {
    }


    @Override
    public Map<String, Object> getErrorAttributes(ServerRequest request, ErrorAttributeOptions options) {
        Throwable error = this.getError(request);
        log.error("Error occurred", error);
        MergedAnnotation<ResponseStatus> responseStatusAnnotation = MergedAnnotations
                .from(error.getClass(), MergedAnnotations.SearchStrategy.TYPE_HIERARCHY).get(ResponseStatus.class);
        HttpStatus errorStatus = findHttpStatus(error, responseStatusAnnotation);

        Map<String, Object> map = super.getErrorAttributes(request, options);
        map.remove("timestamp");
        map.remove("path");
//        map.remove("status");// 注意不能删！别的方法调用之后会使用 map 获取 status，删掉之后 NullPointerException
        String message = (String) map.remove("error");
        map.remove("requestId");

        R<Object> r = R.status(errorStatus).message(message);
        map.put("code", r.getCode());
        map.put("message", r.getMessage());
        map.put("data", r.getData());
        return map;
    }

    private HttpStatus findHttpStatus(Throwable error, MergedAnnotation<ResponseStatus> responseStatusAnnotation) {
        if (error instanceof ResponseStatusException) {
            return ((ResponseStatusException) error).getStatus();
        }
        return responseStatusAnnotation.getValue("code", HttpStatus.class)
                .orElse(INTERNAL_SERVER_ERROR);
    }
}