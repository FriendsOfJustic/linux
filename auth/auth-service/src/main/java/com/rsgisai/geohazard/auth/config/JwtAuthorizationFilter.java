package com.rsgisai.geohazard.auth.config;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.auth.service.TokenService;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.http.HttpStatus;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContext;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.stereotype.Component;
import org.springframework.web.filter.OncePerRequestFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

import static com.rsgisai.geohazard.auth.controller.CommonController.RESPONSE_BODY;

@Component
public class JwtAuthorizationFilter extends OncePerRequestFilter {
    private final ObjectMapper objectMapper;

    private final TokenService tokenService;

    public JwtAuthorizationFilter(TokenService tokenService, ObjectMapper objectMapper) {
        this.tokenService = tokenService;
        this.objectMapper = objectMapper;
    }

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain) throws ServletException, IOException {
        String jws = request.getHeader("token");
        if (jws == null || "/auth-service/login".equals(request.getRequestURI())) {
            filterChain.doFilter(request, response);
            return;
        }

        try {
            boolean validate = tokenService.validate(jws);
            if (validate) {
                UserDetails userDetails = tokenService.parseUserDetails(jws);

                Authentication authentication = new UsernamePasswordAuthenticationToken(userDetails, null, userDetails.getAuthorities());

                SecurityContext context = SecurityContextHolder.createEmptyContext();
                context.setAuthentication(authentication);
                SecurityContextHolder.setContext(context);

                filterChain.doFilter(request, response);
            } else {
                throw new AccessDeniedException("Token Invalid.");
            }
        } catch (Exception e) {
            R<Exception> r = R
                    .<Exception>status(HttpStatus.UNAUTHORIZED)
                    .message("Token Invalid")
                    .data(e);
            request.setAttribute(RESPONSE_BODY, r);
            request.getSession().invalidate();
            request.getRequestDispatcher("/common").forward(request, response);
        }
    }
}
