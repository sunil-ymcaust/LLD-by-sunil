# Spring Boot on Docker connecting to MySQL Docker container

1. Use MySQL Image published by Docker Hub (https://hub.docker.com/_/mysql/)
Command to run the mysql container
`docker run --name mysql-standalone -e MYSQL_ROOT_PASSWORD=password -e MYSQL_DATABASE=test -e MYSQL_USER=sa -e MYSQL_PASSWORD=password -d mysql:5.6`

2. In the Spring Boot Application, use the same container name of the mysql instance in the application.properties
`spring.datasource.url = jdbc:mysql://mysql-standalone:3306/test`

3. Create a `Dockerfile` for creating a docker image from the Spring Boot Application
`FROM openjdk:8
ADD target/users-mysql.jar users-mysql.jar
EXPOSE 8086
ENTRYPOINT ["java", "-jar", "users-mysql.jar"]`

4. Using the Dockerfile create the Docker image.
From the directory of Dockerfile - `docker build . -t users-mysql`

5. Run the Docker image (users-mysql) created in #4.
`docker build . -t users-mysql`

## Useful Docker commands
- `docker images`
- `docker container ls`
- `docker logs <container_name>`
- `docker container rm <container_name`
- `docker image rm <image_name`


#  Kubernetes

## Scaling and Availbility:

For Replication of the application needs to be configured by K8s admin.

Ingress will decide which pod will respond to the user request.

<img width="1459" alt="Screenshot 2023-01-03 at 2 47 18 AM" src="https://user-images.githubusercontent.com/97176448/210278648-371e9b89-1368-448b-83a7-da4c723784c9.png">

## Disaster Recovery :

ETCD check system availabilty and ask new pods and replica started in case of heavy load and also help in disaster recovery as it will create backup of the system and pods, and in case of whole system crash, it will create new pods automatically.

<img width="1422" alt="Screenshot 2023-01-03 at 2 49 21 AM" src="https://user-images.githubusercontent.com/97176448/210278773-42c67576-698c-4eab-8b4f-6bb721d133cf.png">





#  ------------------------------------------SEPARATOR


# LLD Repo
Here I will go through all the LLD Questions and take notes here in the same directory

List of design Patterns done as of now:
Decorator
Builder
Abstract factory
Factory
singleton
Observer
Startegy



List of Question and Link to the resourses
Parking Lot Design [Singleton and SOLID](https://www.youtube.com/watch?v=V9NEOLpt3tg) 

Hotel management System [Decorator Design Pattern and UML](https://www.youtube.com/watch?v=71W8QTdFWw8&list=PL12BCqE-Lp650Cg6FZW7SoZwN8Rw1WJI7&index=3) 


Library Management System

Book My show




# TODO
- [ ] Design True caller	
- [ ] Design Snake and Ladder Game	
- [ ] Design Bill Sharing/Expense Sharing like Splitwise
- [X] Design Amazon Service	(Stratagy Design Pattern for notifications)
- [ ] Design Vehicle / Car Rental Application like Zoomcar
- [ ] Design Distributed Id Generation like Twitter Snowflake id	
- [ ] Implement a logger	
- [ ] Cab Booking like Uber, Ola	
- [X] Design Parking lot system
- [X] Design Chess Game	
- [X] Stackoverflow
- [ ] LFU
- [X] Design an online book reader system	(Library)
- [X] Design an online hotel booking system	(Decorator Design Pattern)
- [ ] Design a Logistics System	
- [ ] Design Tic Tac Toe
- [ ] Design a configuration management system
- [ ] Design a Vending Machine
- [ ] Design Maps Navigator Client for different transportation types (OOD)
- [ ] Design a Json Parser from scratch	
- [X] Design Elevator	
- [X] Design ATM (Factory Design pattern)
- [ ] CricInfo/Cricbuzz
- [ ] TikTok
- [ ] Pinterest
- [X] Movie Ticket Booking
- [ ] Uber Eats/ Door dash/ Swiggy
- [X] LRU
- [X] Stack and Queue
