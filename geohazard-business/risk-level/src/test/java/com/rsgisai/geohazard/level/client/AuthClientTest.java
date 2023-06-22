package com.rsgisai.geohazard.level.client;

import com.rsgisai.geohazard.system.common.R;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @author tfh, created at 2023-04-07 4:55 PM
 */
@SpringBootTest
class AuthClientTest {
    @Autowired
    AuthClient authClient;

    @Test
    void publicKey() {
        R<String> stringR = authClient.publicKey();
        System.out.println("stringR = " + stringR);
    }
}