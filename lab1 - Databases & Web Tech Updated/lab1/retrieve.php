<?php

//Include the config
include "config.php";

?>

<!-- This is an html header 1 tag -->
<h1 style="text-align: center">Sensor Listing</h1>
   
<?php

// Get the option variable
if(isset($_GET['listing'])){

    // Set a condition for the listing. If it is 1 or None the display a json record of the data
    if(($_GET['listing']==1) || ($_GET['listing']=="")){
        $data=array();
        $q=mysqli_query($con,"select * from `iotlab1`");
        while ($row=mysqli_fetch_object($q)){
        $data[]=$row;
        }
        echo json_encode($data);
    }

    // If the listing is 2 then display the data in the table.
    if   ($_GET['listing']==2){
        // Run the query
        $q=mysqli_query($con,"select * from `iotlab1`");

        //All echos display html elements
        echo '<table>';

        echo '<thead>
        <tr>
            <th>DataID</th>
            <th>Sensor Name</th>
            <th>Sensor Type</th>
            <th>Current Reading</th>
            <th>Sensor Location</th>
        </tr>
        </thead>';
        
        // Fill the table body with the values
        while($row = mysqli_fetch_assoc($q)) {            
            echo "<tr>
                    <td>{$row["id"]}</td>
                    <td>{$row["SensorName"]}</td>
                    <td> {$row["SensorType"]}</td>
                    <td> {$row["CurrentReading"]}</td>
                    <td> {$row["SensorLocation"]}</td>
                </tr>";
        }
        echo  "</table>";
    }
}
?>
    