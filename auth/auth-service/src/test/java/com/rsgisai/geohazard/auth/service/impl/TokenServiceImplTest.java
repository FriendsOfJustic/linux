package com.rsgisai.geohazard.auth.service.impl;

import com.rsgisai.geohazard.auth.service.TokenService;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;

import java.security.SignatureException;
import java.util.Collection;
@SpringBootTest
public class TokenServiceImplTest {

    TokenServiceImpl tokenService = new TokenServiceImpl();

    @Test
    public void testParse() throws SignatureException {
        UserDetails user = User.withUsername("Richard")
                .password("not null")
                .authorities("ADMIN", "USER").build();
        String jws = tokenService.generate(user.getUsername(), user.getAuthorities());

        UserDetails userDetails = tokenService.parseUserDetails(jws);
        Collection<? extends GrantedAuthority> authorities = userDetails.getAuthorities();
        for (GrantedAuthority authority : authorities) {
            String authority1 = authority.getAuthority();
            System.out.println("authority1 = " + authority1);
        }
        System.out.println("userDetails = " + userDetails);
    }

    public void testDirect() {
        String publicKey = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4Zq+2hpt9eYeHOAPTYG/QMaB7ZEEqNLrNxHbefjUq9I8Y0FkcTOd8yUO/a7W3wl/Otjz5Wjn4l/XXxq28KVjP8maVH0OtB5QtXaqT/Rj/Meg9N+MFoRk9YBCBtAGCmtBozmKQD2ZDKvst4UFSeuxnYqiFM2DCunjbwj79GQ91Zol9xZIUlsiVEHGECyHEVmeQNF6QBi2kYtKXXqkAwm5NnKt9NN2tgVJFsbf9+THB+SmDf5k7Sh1q3mTiPBO8wExlaYiZ8zvh7wthWgTH3XbWUDyAebeat5V7xr4l+SJW/7mCka0Kjjq9gA3nanuRw/KQfKcaApO/lj6XSQ29QqPnQIDAQAB";

    }

    @Test
    public void testValidate() {
        UserDetails user = User.withUsername("Richard")
                .password("not null")
                .authorities("ADMIN", "USER").build();
        String jws = tokenService.generate(user.getUsername(), user.getAuthorities());

        assert tokenService.validate(jws, tokenService.getPublicKeyString());
        tokenService.updateKeyPair();
        assert !tokenService.validate(jws, tokenService.getPublicKeyString());
    }

    public void testGenerate() {
        UserDetails user = User.withUsername("Richard")
                .password("not null")
                .authorities("ADMIN", "USER").build();
        String generate = tokenService.generate(user.getUsername(), user.getAuthorities());
        System.out.println("generate = " + generate);
    }

    public void testUpdateKeyPair() {
        TokenService tokenService = new TokenServiceImpl();
        String publicKeyString = tokenService.getPublicKeyString();
        System.out.println("publicKeyString = " + publicKeyString);
        tokenService.updateKeyPair();
        String newPublicKey = tokenService.getPublicKeyString();
        System.out.println("publicKeyString = " + newPublicKey);
        assert !newPublicKey.equals(publicKeyString);
    }
}