CREATE DATABASE iotlab4;
USE iotlab4;

CREATE TABLE nodemcu(
DataID int not null auto_increment,
SensorName varchar(50) not null,
SensorType varchar(50),
CurrentReading float not null,
DateRead timestamp,
SensorLocation varchar(50),
`Name` varchar(50),
primary key(DataID)
);
