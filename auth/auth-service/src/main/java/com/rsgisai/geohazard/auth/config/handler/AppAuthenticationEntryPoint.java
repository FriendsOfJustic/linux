package com.rsgisai.geohazard.auth.config.handler;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.http.HttpStatus;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.AuthenticationEntryPoint;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

import static com.rsgisai.geohazard.auth.controller.CommonController.RESPONSE_BODY;

public class AppAuthenticationEntryPoint implements AuthenticationEntryPoint {
    @Override
    public void commence(HttpServletRequest request, HttpServletResponse response, AuthenticationException authException) throws IOException, ServletException {
        R<AuthenticationException> r = R
                .<AuthenticationException>status(HttpStatus.UNAUTHORIZED)
                .message("请登录")
                .data(authException);
        request.setAttribute(RESPONSE_BODY, r);
        request.getSession().invalidate();
        request.getRequestDispatcher("/common").forward(request, response);
    }
}
