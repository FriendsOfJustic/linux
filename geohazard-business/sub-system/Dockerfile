FROM openjdk:8-jdk-alpine
LABEL authors="Richard"

COPY target/sub-system-0.0.1-SNAPSHOT.jar app.jar

EXPOSE 20235

ENTRYPOINT ["java", "-jar", "app.jar", "--spring.profiles.active=prod"]