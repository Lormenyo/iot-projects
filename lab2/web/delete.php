<?php
//Procedural
include "config.php";

//Get the delete option
include "helper_functions.php";
    //Get the id of the data to delete. Remember you can delete based on any column in the table. 
    // Here we are just using the id
    if(isset($_GET['delete']))
     {  
        //let's get the id from the get request
        $id=$_GET['DataID'];
        //Prepare the query
        $sql="delete from `simple_data` where `DataID`='$id'";
        // Excute the query
        $q=mysqli_query($con,$sql);
        //Just a comment to make sure your request works.
        //If the query is true, return 'success' else error
        if($q){
            function_alert("Delete Successful");
            redirectToHome();
         }
           
         else{
            include "index.php";
            function_alert("Error: Could not delete the record.");
            // echo "<h1 style='color: red;'>Error: Could not update the record.</h1>";
         }
     }

?>
