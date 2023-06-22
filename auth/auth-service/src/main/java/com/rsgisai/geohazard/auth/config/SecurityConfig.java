package com.rsgisai.geohazard.auth.config;

import com.rsgisai.geohazard.auth.config.handler.AppAccessDeniedHandler;
import com.rsgisai.geohazard.auth.config.handler.AppAuthenticationEntryPoint;
import com.rsgisai.geohazard.auth.config.handler.AppAuthenticationFailureHandler;
import com.rsgisai.geohazard.auth.entity.ProjectPasswordEncoder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.provisioning.JdbcUserDetailsManager;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.security.web.authentication.AuthenticationSuccessHandler;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;

import javax.sql.DataSource;

@Configuration
public class SecurityConfig {
    final JwtAuthorizationFilter jwtAuthorizationFilter;
    private final AuthenticationSuccessHandler appAuthenticationSuccessHandler;

    public SecurityConfig(
            AuthenticationSuccessHandler appAuthenticationSuccessHandler,
            JwtAuthorizationFilter jwtAuthorizationFilter) {
        this.appAuthenticationSuccessHandler = appAuthenticationSuccessHandler;
        this.jwtAuthorizationFilter = jwtAuthorizationFilter;
    }

    @Bean
    SecurityFilterChain webHttpSecurity(HttpSecurity http) throws Exception {
        http
                .authorizeHttpRequests(authorize -> authorize
                        .antMatchers("/login", "/auth/public_key", "/user-info").permitAll()
                        .antMatchers("/admin/**", "/user-details/**").hasRole("ADMIN")
                        .anyRequest().authenticated()
                )
                .formLogin(login -> login
                        .loginProcessingUrl("/login")
                        .successHandler(appAuthenticationSuccessHandler)
                        .failureHandler(new AppAuthenticationFailureHandler())
                )
                .csrf().disable()
                .sessionManagement().disable()

                .addFilterBefore(jwtAuthorizationFilter, UsernamePasswordAuthenticationFilter.class)

                .exceptionHandling(handle -> handle
                        .authenticationEntryPoint(new AppAuthenticationEntryPoint())
                        .accessDeniedHandler(new AppAccessDeniedHandler()))
        ;
        ;
        return http.build();
    }

    @Bean
    JdbcUserDetailsManager jdbcUserDetailsManager(DataSource dataSource) {
        return new JdbcUserDetailsManager(dataSource);
    }

    @Bean
    public PasswordEncoder passwordEncoder() {
        return ProjectPasswordEncoder.getPasswordEncoder();
    }
}
