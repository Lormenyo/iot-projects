<?php


//Procedural
include "config.php";



if(isset($_GET['insert']))
 {
    $SensorName=$_GET['SensorName'];
    $SensorType=$_GET['SensorType'];
    $CurrentReading=$_GET['CurrentReading'];
    $SensorLocation=$_GET['SensorLocation'];
    $Name=$_GET['Name'];
    
    $sql="INSERT INTO `nodemcu` (`SensorName`,`SensorType`,`CurrentReading`,`SensorLocation`,`Name`) VALUES ('$SensorName','$SensorType' ,'$CurrentReading' ,'$SensorLocation','$Name')";

    $q=mysqli_query($con,$sql);
   

 
 if($q)
  echo "<h1>Inserted Successfully</h1>";
 else
  echo "error";
 
 }
?>