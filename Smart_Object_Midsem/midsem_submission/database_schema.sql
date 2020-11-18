CREATE DATABASE midsem;
USE midsem;

CREATE TABLE smart_object(
DataID int not null auto_increment,
SensorName varchar(50) not null,
SensorType varchar(50),
averageSensorValue float not null,
ActuatorType varchar(50),
ActuatorValue varchar(50),
MillisTime BIGINT,
DateRead timestamp,
Location varchar(50),
`Name` varchar(50),
primary key(DataID)
);
