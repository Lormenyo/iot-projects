drop database final;
create database final;
use final;

create table mysensors(
    DataID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    Led1 varchar(50) not null,
    Led2 varchar(50) not null,
    ServoMotor varchar(50) not null,
    temperature float not null,
    humidity float not null,
    ldr float not null,
    TimeRead timestamp
);