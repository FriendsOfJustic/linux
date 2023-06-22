package com.rsgisai.geohazard.auth.service.impl;

import com.rsgisai.geohazard.auth.service.TokenService;
import com.rsgisai.geohazard.auth.util.JwtUtil;
import io.jsonwebtoken.*;
import io.jsonwebtoken.io.Decoders;
import io.jsonwebtoken.io.Encoders;
import io.jsonwebtoken.security.Keys;
import io.jsonwebtoken.security.SignatureException;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.stereotype.Service;

import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.Collection;
import java.util.Date;

@Service
public class TokenServiceImpl implements TokenService {
    private KeyPair keyPair = Keys.keyPairFor(SignatureAlgorithm.RS256);
    KeyFactory keyFactory;

    {
        try {
            keyFactory = KeyFactory.getInstance("RSA");
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public String generate(String username, Collection<? extends GrantedAuthority> authorities) {
        return Jwts.builder()
                .setExpiration(new Date(System.currentTimeMillis() + 30 * 60 * 1000))// 30 minutes
                .claim("username", username)
                .claim("authorities", authorities)
                .signWith(keyPair.getPrivate())
                .compact();
    }

    @Override
    public String getPublicKeyString() {
        return Encoders.BASE64.encode(
                getPublicKey().getEncoded()
        );
    }

    public PublicKey getPublicKey() {
        return keyPair.getPublic();
    }

    @Override
    public void updateKeyPair() {
        keyPair = Keys.keyPairFor(SignatureAlgorithm.RS256);
    }

    @Override
    public boolean validate(String jws, String publicKeyString) {
        try {
            PublicKey publicKey = JwtUtil.parsePublicKey(publicKeyString);
            Jwts.parserBuilder()
                    .setSigningKey(publicKey)
                    .build()
                    .parse(jws);
            return true;
        } catch (InvalidKeySpecException e) {
            throw new RuntimeException(e);
        } catch (ExpiredJwtException | MalformedJwtException | SignatureException | IllegalArgumentException e) {
            return false;
        }
    }

    @Override
    public boolean validate(String jws) {
        return validate(jws, getPublicKeyString());
    }


    @Override
    public UserDetails parseUserDetails(String jws) throws java.security.SignatureException {
        return JwtUtil.jwsToUserDetails(jws, keyPair.getPublic());
//        ObjectMapper objectMapper = new ObjectMapper();
//        JwtParser jwtParser = Jwts.parserBuilder()
//                .setSigningKey(keyPair.getPublic())
//                .deserializeJsonWith(new JacksonDeserializer<>(new ObjectMapper()))
//                .build();
//
//        Jws<Claims> jwt = jwtParser.parseClaimsJws(jws);
//        Claims body = jwt.getBody();
//        String username = (String) body.get("username");
//        Collection<Map<String, Object>> authorities = (Collection<Map<String, Object>>) body.get("authorities");
//        List<GrantedAuthority> authorityCollection = authorities.stream().map(m -> (GrantedAuthority) () -> (String) m.get("authority")).collect(Collectors.toList());
//        return User.withUsername(username)
//                .password("not null")
//                .authorities(authorityCollection)
//                .build()
//                ;
    }
}
