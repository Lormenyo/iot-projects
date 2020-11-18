<?php
//Include the config file
include "config.php";
include "helper_functions.php";

//get option
if(isset($_GET['insert']))
 {
   //get the data values
   $SensorName=$_GET['SensorName'];
   $SensorType=$_GET['SensorType'];
   $CurrentReading=$_GET['CurrentReading'];
   $SensorLocation=$_GET['SensorLocation'];
   
   //Run the query for insertion into the table name
   $sql="INSERT INTO `simple_data` (`SensorName`,`SensorType`,`CurrentReading`,`SensorLocation`) 
         VALUES ('$SensorName','$SensorType' ,'$CurrentReading' ,'$SensorLocation')";
   
   //Execute the query
   $q=mysqli_query($con,$sql);
   //Just a comment to make sure your request works.
   //If the query is true, return 'success' else error
   if($q){
      redirectToHome();
      function_alert("Insert Successful");
   }
     
   else{
      include "index.php";
      function_alert("Error: Could not insert the record.");
      // echo "<h1 style='color: red;'>Error: Could not update the record.</h1>";
   }
 }
?>