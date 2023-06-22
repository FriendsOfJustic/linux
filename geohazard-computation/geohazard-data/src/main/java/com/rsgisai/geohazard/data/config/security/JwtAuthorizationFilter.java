package com.rsgisai.geohazard.data.config.security;

import com.rsgisai.geohazard.auth.TokenNotProvidedException;
import com.rsgisai.geohazard.auth.util.JwtUtil;
import com.rsgisai.geohazard.data.service.impl.AuthServiceImpl;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.context.SecurityContext;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.web.authentication.session.SessionAuthenticationStrategy;
import org.springframework.security.web.context.SecurityContextRepository;
import org.springframework.stereotype.Component;
import org.springframework.web.filter.GenericFilterBean;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.security.SignatureException;
import java.util.Collection;
import java.util.HashSet;


/**
 * @author tfh, created at 2023-05-16 9:33 PM
 */
@Component
public class JwtAuthorizationFilter extends GenericFilterBean {

    private final AuthServiceImpl authService;

    public JwtAuthorizationFilter(AuthServiceImpl authService) {
        this.authService = authService;
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        doFilter((HttpServletRequest) request, (HttpServletResponse) response, chain);
    }

    private void doFilter(HttpServletRequest request, HttpServletResponse response, FilterChain chain) throws ServletException, IOException {
        /**
         String token = request.getHeader("token");
         if (token == null) throw new TokenNotProvidedException();

         // 尝试解析两次，因为第一次有可能 public key 过期
         UserDetails userDetails;
         try {
         userDetails = JwtUtil.jwsToUserDetails(token, authService.getPublicKey());
         } catch (SignatureException s) {
         try {
         userDetails = JwtUtil.jwsToUserDetails(token, authService.getLatestPublicKey());
         } catch (SignatureException e) {
         throw new RuntimeException(e);
         }
         }
         */
        Collection<? extends GrantedAuthority> authorities = new HashSet<>();
        UserDetails userDetails = new User("admin", "123456", authorities);
        Authentication authentication = new UsernamePasswordAuthenticationToken(
                userDetails.getUsername(), null, userDetails.getAuthorities());

        SecurityContext securityContext = SecurityContextHolder.createEmptyContext();
        securityContext.setAuthentication(authentication);
        SecurityContextHolder.setContext(securityContext);

        chain.doFilter(request, response);
    }
}
