<?php
//Procedural
include "config.php";

//Get the delete option
if(isset($_GET['delete']))

    //Get the id of the data to delete. Remember you can delete based on any column in the table. 
    // Here we are just using the id
    if(isset($_GET['id']))
     {  
        //let's get the id from the get request
        $id=$_GET['id'];

        //Prepare the query
        $sql="delete from `iotlab1` where `id`='$id'";

        // Excute the query
        $q=mysqli_query($con,$sql);

        //Just a comment to make sure your request works.
        //If the query is true, return 'success' else error
        if($q)
            echo "<h1>success</h1>";
        else
            echo "<h1 style='color: red;'>Error: Couldno delete the record.</h1>";
     }

?>
