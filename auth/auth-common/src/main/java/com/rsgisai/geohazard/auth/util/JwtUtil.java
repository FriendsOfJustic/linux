package com.rsgisai.geohazard.auth.util;

import com.fasterxml.jackson.databind.ObjectMapper;
import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jws;
import io.jsonwebtoken.JwtParser;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.io.Decoders;
import io.jsonwebtoken.jackson.io.JacksonDeserializer;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;

import java.security.KeyFactory;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.SignatureException;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * @author tfh, created at 2023-05-16 9:14 PM
 */
public class JwtUtil {
    private static KeyFactory keyFactory;

    static {
        try {
            keyFactory = KeyFactory.getInstance("RSA");
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * @param jws       加密的JWT
     * @param publicKey 加密此JWT对应的公钥
     * @return spring security 的 UserDetails 对象，可以用于获取 '用户名' 和 '权限'
     */
    public static UserDetails jwsToUserDetails(String jws, PublicKey publicKey) throws SignatureException {

        JwtParser jwtParser = Jwts.parserBuilder()
                .setSigningKey(publicKey)
                .deserializeJsonWith(new JacksonDeserializer<>(new ObjectMapper()))
                .build();

        Jws<Claims> jwt = jwtParser.parseClaimsJws(jws);
        Claims body = jwt.getBody();
        String username = (String) body.get("username");
        Collection<Map<String, Object>> authorities = (Collection) body.get("authorities");
        List<GrantedAuthority> authorityCollection = authorities.stream()
                .map(m -> (GrantedAuthority) () -> (String) m.get("authority"))
                .collect(Collectors.toList());
        return User.withUsername(username)
                .password("not null")// password can't be null
                .authorities(authorityCollection)
                .build()
                ;
    }

    public static PublicKey parsePublicKey(String publicKeyEncoded) throws InvalidKeySpecException {
        X509EncodedKeySpec x509EncodedKeySpec = new X509EncodedKeySpec(Decoders.BASE64.decode(publicKeyEncoded));
        return keyFactory.generatePublic(x509EncodedKeySpec);
    }
}
