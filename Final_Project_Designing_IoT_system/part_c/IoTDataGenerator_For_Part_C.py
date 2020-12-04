import paho .mqtt .publish as publish #line:1
import time #line:2
import random #line:3
import threading #line:4
MQTT_SERVER ="localhost"#line:9
MQTT_PATH1 ="IoTClass/devices/temp1"#line:10
MQTT_PATH2 ="IoTClass/devices/temp2"#line:11
MQTT_PATH3 ="IoTClass/devices/ldr"#line:12
MQTT_PATH4 ="IoTClass/devices/heater"#line:13
MQTT_PATH5 ="IoTClass/devices/humidity1"#line:14
MQTT_PATH6 ="IoTClass/devices/humidity2"#line:15
MQTT_PATH7 ="IoTClass/devices/pump"#line:16
temp =0 #line:18
tempStatus =0 #line:19
def mqttHandler_thread1 (O000O00OO0OOOO0OO ):#line:22
    print ("thread1 started- temperature1")#line:23
    while True :#line:25
        global tempStatus #line:26
        tempStatus =random .randint (30 ,40 )#line:27
        publish .single (MQTT_PATH1 ,payload =tempStatus ,retain =True )#line:28
        time .sleep (1 )#line:31
def mqttHandler_thread2 (O00OOOOO00O000OO0 ):#line:34
    print ("thread2 started - temperature2")#line:35
    OO00OOO0O0OO0O000 =0 #line:36
    while True :#line:37
        OOO0OOOOOOOO00000 =random .randint (20 ,30 )#line:38
        publish .single (MQTT_PATH2 ,payload =OOO0OOOOOOOO00000 ,retain =True )#line:39
        time .sleep (1 )#line:42
def mqttHandler_thread3 (OO0O0000O0000O00O ):#line:45
    print ("thread3 started - LDR")#line:46
    O00OO0OOO000OO0O0 =0 #line:47
    while True :#line:48
        if tempStatus <35 :#line:49
            O0OO0O0O0O0000OOO =random .randint (10 ,400 )#line:50
        else :#line:51
            O0OO0O0O0O0000OOO =random .randint (600 ,999 )#line:52
        publish .single (MQTT_PATH3 ,payload =O0OO0O0O0O0000OOO ,retain =True )#line:53
        time .sleep (3 )#line:56
def mqttHandler_thread4 (OO00O0OO0000O0OOO ):#line:59
    print ("thread4 started - heater")#line:60
    OOO0000OOOO0O0000 =0 #line:61
    while True :#line:62
        OO00000OO0OOO0O00 =random .randint (0 ,1 )#line:63
        if OO00000OO0OOO0O00 ==0 :#line:64
            O000O0OO0O00OOO00 ="OFF"#line:65
        else :#line:66
            O000O0OO0O00OOO00 ="ON"#line:67
        publish .single (MQTT_PATH4 ,payload =O000O0OO0O00OOO00 ,retain =True )#line:68
        time .sleep (5 )#line:71
def mqttHandler_thread5 (O0OOO0O00OOO0O000 ):#line:74
    print ("thread5 started - humidity1")#line:75
    OOO0OO000OO0OO000 =0 #line:76
    while True :#line:77
        O0OOO0OO0OOOO0OO0 =random .randint (5 ,60 )#line:78
        publish .single (MQTT_PATH5 ,payload =O0OOO0OO0OOOO0OO0 ,retain =True )#line:79
        time .sleep (1 )#line:82
def mqttHandler_thread6 (O00O000000O00OOOO ):#line:85
    print ("thread6 started - humidity2")#line:86
    O000000O000000OO0 =0 #line:87
    while True :#line:88
        O0OOOOOO0O00O000O =random .randint (40 ,100 )#line:89
        publish .single (MQTT_PATH6 ,payload =O0OOOOOO0O00O000O ,retain =True )#line:90
        time .sleep (1 )#line:93
def mqttHandler_thread7 (OOOO00OO0O0OO0O00 ):#line:96
    print ("thread1 started - pump")#line:97
    O00OO0OOO0O0O00O0 =0 #line:98
    while True :#line:99
        OOO0O00O0OOOO0000 =random .randint (0 ,1 )#line:100
        if OOO0O00O0OOOO0000 ==0 :#line:101
            O000OOO000OOOOOO0 ="OFF"#line:102
        else :#line:103
            O000OOO000OOOOOO0 ="ON"#line:104
        publish .single (MQTT_PATH7 ,payload =O000OOO000OOOOOO0 ,retain =True )#line:105
        time .sleep (5 )#line:108
print ("\n\nIt will be best to start your clients FIRST , so you do not lose data\n\n")#line:113
print ("\n\n This will ran for 45mins  \n\n Let it run in the background")#line:114
x1 =threading .Thread (target =mqttHandler_thread1 ,args =(1 ,),daemon =True )#line:116
x1 .start ()#line:117
x2 =threading .Thread (target =mqttHandler_thread2 ,args =(2 ,),daemon =True )#line:118
x2 .start ()#line:119
x3 =threading .Thread (target =mqttHandler_thread3 ,args =(3 ,),daemon =True )#line:120
x3 .start ()#line:121
x4 =threading .Thread (target =mqttHandler_thread4 ,args =(4 ,),daemon =True )#line:122
x4 .start ()#line:123
x5 =threading .Thread (target =mqttHandler_thread5 ,args =(5 ,),daemon =True )#line:124
x5 .start ()#line:125
x6 =threading .Thread (target =mqttHandler_thread6 ,args =(6 ,),daemon =True )#line:126
x6 .start ()#line:127
x7 =threading .Thread (target =mqttHandler_thread7 ,args =(7 ,),daemon =True )#line:128
x7 .start ()#line:129
time .sleep (45 *60 );#line:137
print ("\n\n\nFinished pumping data.\n\n")#line:138
