<?php
//Procedural
include "config.php";

//Get the delete option


    //Get the id of the data to delete. Remember you can delete based on any column in the table. 
    // Here we are just using the id
    if(isset($_GET['DataID']))
     {  
        //let's get the id from the get request
        $id=$_GET['DataID'];

        //Prepare the query
        $sql="delete from `simple_data` where `DataID`='$id'";

        // Excute the query
        $q=mysqli_query($con,$sql);

        //Just a comment to make sure your request works.
        //If the query is true, return 'success' else error
        if($q)
            // echo "<h1>success</h1>";
            include "index.php";
        else
            echo "<h1 style='color: red;'>Error: Couldno delete the record.</h1>";
     }

?>
