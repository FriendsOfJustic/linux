FROM openjdk:8-jdk-alpine
LABEL authors="石海涛"

COPY target/geohazard-chain-0.0.1-SNAPSHOT.jar app.jar

EXPOSE 20231

ENTRYPOINT ["java", "-jar", "app.jar", "--spring.profiles.active=prod"]
