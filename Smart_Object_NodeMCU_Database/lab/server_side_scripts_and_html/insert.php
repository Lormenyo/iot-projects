<?php


//Procedural
include "config.php";



if(isset($_GET['insert']))
 {
    $SensorName=$_GET['SensorName'];
    $SensorType=$_GET['SensorType'];
    $averageSensorValue=$_GET['averageSensorValue'];
    $Location=$_GET['Location'];
    $Name=$_GET['Name'];
    $MillisTime=$_GET['MillisTime'];
    $ActuatorType=$_GET['ActuatorType'];
    $ActuatorValue=$_GET['ActuatorValue'];
    
    $sql="INSERT INTO `smart_object` (`SensorName`,`SensorType`,`averageSensorValue`, `ActuatorType`,`ActuatorValue`, `Location`,`Name`, `MillisTime`)
         VALUES ('$SensorName','$SensorType' ,'$averageSensorValue', '$ActuatorType','$ActuatorValue', '$Location','$Name', '$MillisTime' )";

    $q=mysqli_query($con,$sql);
   

 
 if($q)
  echo "<h1>Inserted Successfully</h1>";
 else
  echo "error";
 
 }
?>