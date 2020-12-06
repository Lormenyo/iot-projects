use final;

create table subscriber(
    DataID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    temp1 float not null,
    temp2 float not null,
    ldr float not null,
    heater varchar(50) not null,
    humidity1 float not null,
    humidity2 float not null,
    pump varchar(50) not null,    
    TimeRead timestamp
);