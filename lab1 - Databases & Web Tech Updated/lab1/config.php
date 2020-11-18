<?php
    //Specify the database credentials
    $servername= "localhost";
    $username="root";
    $password="";
    $dbname="iot";

    //connect to the database
    $con = mysqli_connect($servername,$username,$password,$dbname) or die ("could not connect database");

?>

