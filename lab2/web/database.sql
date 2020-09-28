create database IoTLab2;
use IoTLab2;

create table simple_data(
    DataID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    SensorName varchar(80) not null,
    SensorType varchar(90),
    SensorLocation varchar(80) not null,
    CurrentReading float,
    DateRead timestamp
);