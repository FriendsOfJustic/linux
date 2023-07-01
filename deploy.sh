#!/usr/bin/env bash

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

cd ${script_dir}/eureka-server
docker build --tag geohazard-eureka .
docker stop geohazard-eureka
docker rm geohazard-eureka
docker run --name geohazard-eureka --detach --network=geohazard --publish 20222:20222 geohazard-eureka

cd ${script_dir}/gateway
docker build --tag geohazard-gateway .
docker stop geohazard-gateway
docker rm geohazard-gateway
docker run --name geohazard-gateway --detach --network=geohazard --publish 20223:20223 geohazard-gateway


cd ${script_dir}/geohazard-business/sub-system
docker build --tag geohazard-sub-system .
docker stop geohazard-sub-system
docker rm geohazard-sub-system
docker run --name geohazard-sub-system --detach --network=geohazard --publish 20235:20235 geohazard-sub-system

cd ${script_dir}/geohazard-business/risk-level
docker build --tag geohazard-risk-level .
docker stop geohazard-risk-level
docker rm geohazard-risk-level
docker run --name geohazard-risk-level --detach --network=geohazard --publish 20234:20234 geohazard-risk-level

cd ${script_dir}/geohazard-computation/geohazard-data
docker build --tag geohazard-data .
docker stop geohazard-data
docker rm geohazard-data
docker run --name geohazard-data --detach --network=geohazard --publish 20242:20242 geohazard-data

cd ${script_dir}/geohazard-computation/geospatial-computation
docker build --tag geohazard-geospatial-computation .
docker stop geohazard-geospatial-computation
docker rm geohazard-geospatial-computation
docker run --name geohazard-geospatial-computation --detach --network=geohazard --publish 20241:20241 geohazard-geospatial-computation


cd ${script_dir}/geohazard-business/geohazard-chain
docker build --tag geohazard-chain .
docker stop geohazard-chain
docker rm geohazard-chain
docker run --name geohazard-chain --detach --network=geohazard  --add-host=myhost:122.112.250.145 --publish 20231:20231 geohazard-chain