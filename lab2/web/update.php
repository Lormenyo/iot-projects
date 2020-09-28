<?php

//Include the config file
include "config.php";

//Set the option variable
if(isset($_GET['update']))
{
   //Get the data values
   $SensorName=$_GET['SensorName'];
   $SensorType=$_GET['SensorType'];
   $CurrentReading=$_GET['CurrentReading'];
   $SensorLocation=$_GET['SensorLocation'];
   $id=$_GET['id'];

   // Run the update query to update the values in the table field based on 'id'
   // You can set the condtion to anything. Here were are using the $id requested from the get request.
   $sql="UPDATE `simple_data` SET 
            `SensorName`='$SensorName',
            `SensorType`='$SensorType',
            `CurrentReading`='$CurrentReading',
            `SensorLocation`='$SensorLocation' where `id`='$id'";

   //Execute the query
   $q=mysqli_query($con, $sql);

   //Just a comment to make sure your request works.
   //If the query is true, return 'success' else error
   if($q)
      echo "<h1>success</h1>";
   else
      echo "<h1 style='color: red;'>Error: Could not update the record.</h1>";
}

?>