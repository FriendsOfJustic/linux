package com.rsgisai.gateway.client;

import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.ParameterizedTypeReference;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.reactive.function.client.WebClient;
import reactor.core.publisher.Mono;
import reactor.core.publisher.SynchronousSink;

import java.util.function.BiConsumer;

@Component
public class AuthClient {
    private final WebClient.Builder webClientBuilder;

    public AuthClient(WebClient.Builder webClientBuilder) {
        this.webClientBuilder = webClientBuilder;
    }

    //    @GetMapping("/auth/public_key")
    public Mono<String> fetchPublicKey() {
        WebClient webClient = webClientBuilder.build();
        Mono<R<String>> r = webClient.get()
                .uri("http://auth-service/auth-service/auth/public_key")// 第一个 auth-service 是服务名，第二个是 servlet context
                .retrieve()
                .bodyToMono(new ParameterizedTypeReference<R<String>>() {
                });
        return r.map(R::getData);
    }
}
