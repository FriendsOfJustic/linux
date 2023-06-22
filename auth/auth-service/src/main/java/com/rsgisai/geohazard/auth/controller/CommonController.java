package com.rsgisai.geohazard.auth.controller;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpServletRequest;
import java.util.Map;

@RestController
@RequestMapping("/common")
public class CommonController {
    public static final String RESPONSE_BODY = "RESPONSE_BODY";

    @RequestMapping
    public R<?> common(HttpServletRequest request) {
        Object responseBody = request.getAttribute(RESPONSE_BODY);
        if (responseBody instanceof R) {
            return (R<?>) responseBody;
        } else {
            throw new RuntimeException("类型错误，请检查传入参数是否为R，request attribute 名称是否为 'response_body'");
        }
    }
}
