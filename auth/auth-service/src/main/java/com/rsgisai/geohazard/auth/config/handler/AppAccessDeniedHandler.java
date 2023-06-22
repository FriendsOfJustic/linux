package com.rsgisai.geohazard.auth.config.handler;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.http.HttpStatus;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.web.access.AccessDeniedHandler;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

import static com.rsgisai.geohazard.auth.controller.CommonController.RESPONSE_BODY;

public class AppAccessDeniedHandler implements AccessDeniedHandler {
    @Override
    public void handle(HttpServletRequest request, HttpServletResponse response, AccessDeniedException accessDeniedException) throws IOException, ServletException {
        R<AccessDeniedException> r = R
                .<AccessDeniedException>status(HttpStatus.FORBIDDEN)
                .message("没有访问权限")
                .data(accessDeniedException);
        request.setAttribute(RESPONSE_BODY, r);
        request.getSession().invalidate();
        request.getRequestDispatcher("/common").forward(request, response);
    }
}
