FROM openjdk:8-jdk-alpine
LABEL authors="Richard"

COPY target/gateway-0.0.1-SNAPSHOT.jar app.jar

EXPOSE 20223

ENTRYPOINT ["java", "-jar", "app.jar", "--spring.profiles.active=prod"]
