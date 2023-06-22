FROM openjdk:8-jdk-alpine
LABEL authors="Richard"

COPY target/auth-service-0.0.1-SNAPSHOT.jar app.jar

EXPOSE 20221

ENTRYPOINT ["java", "-jar", "app.jar"]