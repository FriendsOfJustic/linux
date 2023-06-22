package com.rsgisai.geohazard.auth.config.handler;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.authentication.AuthenticationFailureHandler;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

import static com.rsgisai.geohazard.auth.controller.CommonController.RESPONSE_BODY;

public class AppAuthenticationFailureHandler implements AuthenticationFailureHandler {
    @Override
    public void onAuthenticationFailure(HttpServletRequest request, HttpServletResponse response, AuthenticationException exception) throws IOException, ServletException {
        R<Object> r = R.fail("登陆失败").data(exception);
        request.setAttribute(RESPONSE_BODY, r);
        request.getRequestDispatcher("/common").forward(request, response);
    }
}
