#!/usr/bin/env bash

docker save -o geohazard-risk-level.tar geohazard-risk-level
docker save -o geohazard-gateway.tar geohazard-gateway
docker save -o geohazard-eureka.tar geohazard-eureka
docker save -o geohazard-data.tar geohazard-data
docker save -o geohazard-chain.tar geohazard-chain