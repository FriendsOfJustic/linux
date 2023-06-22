package com.rsgisai.geohazard.auth.config.handler;

import com.rsgisai.geohazard.auth.service.TokenService;
import com.rsgisai.geohazard.system.common.R;
import lombok.extern.slf4j.Slf4j;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.web.authentication.AuthenticationSuccessHandler;
import org.springframework.stereotype.Component;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Collections;
import java.util.Map;

import static com.rsgisai.geohazard.auth.controller.CommonController.RESPONSE_BODY;

@Slf4j
@Component
public class AppAuthenticationSuccessHandler implements AuthenticationSuccessHandler {
    private final TokenService tokenService;

    public AppAuthenticationSuccessHandler(TokenService tokenService) {
        this.tokenService = tokenService;
    }

    @Override
    public void onAuthenticationSuccess(HttpServletRequest request, HttpServletResponse response, Authentication authentication) throws IOException, ServletException {
        User user = (User) authentication.getPrincipal();
        String token = tokenService.generate(user.getUsername(), user.getAuthorities());
        R<Map<String, String>> r = R.success(Collections.singletonMap("token", token)).message("登陆成功");
        request.setAttribute(RESPONSE_BODY, r);
        request.getSession().invalidate();
        authentication.setAuthenticated(false);
        request.getRequestDispatcher("/common").forward(request, response);
    }
}

