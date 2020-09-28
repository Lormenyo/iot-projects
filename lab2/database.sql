create database iot;

create table iotlab1(
    id int not null auto_increment,
    SensorName varchar(80),
    SensorType varchar(90),
    SensorLocation varchar(80),
    CurrentReading float,
    primary key (id)
);