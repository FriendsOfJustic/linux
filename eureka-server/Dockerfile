FROM openjdk:8-jdk-alpine
LABEL authors="Richard"

COPY target/eureka-server-0.0.1-SNAPSHOT.jar app.jar

EXPOSE 20222

ENTRYPOINT ["java", "-jar", "app.jar"]