create database final;
use final;

create table subscriber(
    DataID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    DeviceName varchar(80) not null,
    DeviceType varchar(90),
    CurrentReading float,
    DateRead timestamp
);