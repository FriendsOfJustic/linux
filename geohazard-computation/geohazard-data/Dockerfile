FROM postgis_java11

# Copy the built JAR file from the builder stage
COPY target/geohazard-data-0.0.1-SNAPSHOT.jar app.jar

EXPOSE 20242

# Set the entry point for the container
ENTRYPOINT ["java", "-jar", "app.jar", "--spring.profiles.active=prod"]
