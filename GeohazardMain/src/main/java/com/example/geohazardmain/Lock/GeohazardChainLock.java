package com.example.geohazardmain.Lock;


import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;
import org.springframework.stereotype.Component;

import java.util.concurrent.locks.ReentrantLock;

@AllArgsConstructor
@NoArgsConstructor
public class GeohazardChainLock {
    public ReentrantLock lock;
}
