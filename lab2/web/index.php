<!DOCTYPE html>
<html lang="en">

<head>
    <!-- Required meta tags-->
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="au theme template">
    <meta name="author" content="Hau Nguyen">
    <meta name="keywords" content="au theme template">

    <!-- Title Page-->
    <title>Dashboard</title>

    <!-- Fontfaces CSS-->
    <link href="css/font-face.css" rel="stylesheet" media="all">
    <link href="vendor/font-awesome-4.7/css/font-awesome.min.css" rel="stylesheet" media="all">
    <link href="vendor/font-awesome-5/css/fontawesome-all.min.css" rel="stylesheet" media="all">
    <link href="vendor/mdi-font/css/material-design-iconic-font.min.css" rel="stylesheet" media="all">

    <!-- Bootstrap CSS-->
    <link href="vendor/bootstrap-4.1/bootstrap.min.css" rel="stylesheet" media="all">

    <!-- Vendor CSS-->
    <link href="vendor/animsition/animsition.min.css" rel="stylesheet" media="all">
    <link href="vendor/bootstrap-progressbar/bootstrap-progressbar-3.3.4.min.css" rel="stylesheet" media="all">
    <link href="vendor/wow/animate.css" rel="stylesheet" media="all">
    <link href="vendor/css-hamburgers/hamburgers.min.css" rel="stylesheet" media="all">
    <link href="vendor/slick/slick.css" rel="stylesheet" media="all">
    <link href="vendor/select2/select2.min.css" rel="stylesheet" media="all">
    <link href="vendor/perfect-scrollbar/perfect-scrollbar.css" rel="stylesheet" media="all">

    <!-- Main CSS-->
    <link href="css/theme.css" rel="stylesheet" media="all">

</head>


<body class="animsition">
    <div class="page-wrapper">
        <!-- HEADER MOBILE-->
        <header class="header-mobile d-block d-lg-none">
            <div class="header-mobile__bar">
                <div class="container-fluid">
                    <div class="header-mobile-inner">
                        <a class="logo" href="index.html">
                            <img src="images/icon/sp.png" alt="CoolAdmin" style="height: 70px; width:100px" />
                        </a>
                        <button class="hamburger hamburger--slider" type="button">
                            <span class="hamburger-box">
                                <span class="hamburger-inner"></span>
                            </span>
                        </button>
                    </div>
                </div>
            </div>
            <nav class="navbar-mobile">
                <div class="container-fluid">
                    <ul class="navbar-mobile__list list-unstyled">
                        <li class="has-sub">
                            <a class="js-arrow" href="index.php">
                                <i class="fas fa-tachometer-alt"></i>Dashboard</a>
                        </li>
                        <li>
                            <a href="listings.php?listing=1">
                                <i class="far fa-check-square"></i>Listings</a>
                        </li>
                    </ul>
                </div>
            </nav>
        </header>
        <!-- END HEADER MOBILE-->

        <!-- MENU SIDEBAR-->
        <aside class="menu-sidebar d-none d-lg-block">
            <div class="logo">
                <a href="#">
                    <img src="images/icon/sp.png" alt="Cool Admin" style="height: 100px" />
                </a>
            </div>
            <div class="menu-sidebar__content js-scrollbar1">
                <nav class="navbar-sidebar">
                    <ul class="list-unstyled navbar__list">
                        <li class="active has-sub">
                            <a class="js-arrow" href="index.php">
                                <i class="fas fa-tachometer-alt"></i>Dashboard</a>
                        </li>
                        <li>
                            <a href="listings.php?listing=1">
                                <i class="far fa-check-square"></i>Listings</a>
                        </li>
                    </ul>
                </nav>
            </div>
        </aside>
        <!-- END MENU SIDEBAR-->




        <!-- Modal for ADDING DATA-->
        <div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel"
            aria-hidden="true">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="exampleModalLabel">Add New Data</h5>
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                            <span aria-hidden="true">&times;</span>
                        </button>
                    </div>
                    <div class="modal-body">
                        <form action="insert.php">
                            <input type="text" class="form-control" style="display: none;" value="1" name="insert">
                            <div class="form-group">
                                <label for="name"> Sensor Name</label>
                                <input type="text" class="form-control" id="name" placeholder="eg DHT22, LDR3, etc "
                                    name="SensorName">
                            </div>
                            <div class="form-group">
                                <label for="type">Sensor Type</label>
                                <input type="text" class="form-control" id="type" placeholder="eg Temperature"
                                    name="SensorType">
                            </div>
                            <div class="form-group">
                                <label for="location">Location</label>
                                <input type="text" class="form-control" id="location" name="SensorLocation"
                                    placeholder="eg R115">
                            </div>
                            <div class="form-group">
                                <label for="reading">Sensor reading</label>
                                <input type="number" step=any class="form-control" id="reading" name="CurrentReading"
                                    placeholder="eg 23.7">
                            </div>
                            <button type="submit" class="btn btn-primary">Submit</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                        <!-- <button type="button" class="btn btn-primary">Save changes</button> -->
                    </div>
                </div>
            </div>
        </div>



        <!-- Modal  for DELETE-->
        <div class="modal fade" id="deleteModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel"
            aria-hidden="true">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="exampleModalLabel">Add New Data</h5>
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                            <span aria-hidden="true">&times;</span>
                        </button>
                    </div>
                    <div class="modal-body">
                        <form action="delete.php">
                            <input type="text" class="form-control" style="display: none;" value="1" name="delete">
                            <div class="form-group">
                                <label for="DataID">Data ID</label>
                                <input type="number" class="form-control" id="DataID" name="DataID" placeholder="ID">
                            </div>
                            <button type="submit" class="btn btn-primary">Submit</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                        <!-- <button type="button" class="btn btn-primary">Save changes</button> -->
                    </div>
                </div>
            </div>
        </div>

        <!-- Modal  for UPDATE -->
        <div class="modal fade" id="updateModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel"
            aria-hidden="true">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="exampleModalLabel">Add New Data</h5>
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                            <span aria-hidden="true">&times;</span>
                        </button>
                    </div>
                    <div class="modal-body">
                        <form action="update.php">
                            <input type="text" class="form-control" style="display: none;" value="1" name="update">
                            <div class="form-group">
                                <label for="DataID">Data ID</label>
                                <input type="number" class="form-control" id="DataID" name="DataID" placeholder="ID">
                            </div>
                            <div class="form-group">
                                <label for="name"> Sensor Name</label>
                                <input type="text" class="form-control" id="name" placeholder="eg DHT22, LDR3, etc "
                                    name="SensorName">
                            </div>
                            <div class="form-group">
                                <label for="type">Sensor Type</label>
                                <input type="text" class="form-control" id="type" placeholder="eg Temperature"
                                    name="SensorType">
                            </div>
                            <div class="form-group">
                                <label for="location">Location</label>
                                <input type="text" class="form-control" id="location" name="SensorLocation"
                                    placeholder="eg R115">
                            </div>
                            <div class="form-group">
                                <label for="reading">Sensor reading</label>
                                <input type="number" step=any class="form-control" id="reading" name="CurrentReading"
                                    placeholder="eg 23.7">
                            </div>
                            <button type="submit" class="btn btn-primary">Submit</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                        <!-- <button type="button" class="btn btn-primary">Save changes</button> -->
                    </div>
                </div>
            </div>
        </div>
        <!-- PAGE CONTAINER-->
        <div class="page-container">
            <!-- HEADER DESKTOP-->
            <header class="header-desktop">
                <div class="section__content section__content--p30">
                    <div class="container-fluid">
                        <div class="header-wrap">
                            <div class="header-button">

                                <div class="account-wrap">
                                    <div class="account-item clearfix js-item-menu">
                                        <div class="image">
                                            <img src="images/icon/avat.png" alt="John Doe" />
                                        </div>
                                        <div class="content">
                                            <a class="js-acc-btn" href="#">Hannah Lormenyo</a>
                                        </div>
                                        <div class="account-dropdown js-dropdown">
                                            <div class="info clearfix">
                                                <div class="image">
                                                    <a href="#">
                                                        <img src="images/icon/avat.png" alt="John Doe" />
                                                    </a>
                                                </div>
                                                <div class="content">
                                                    <h5 class="name">
                                                        <a href="#">Hannah Lormenyo </a>
                                                    </h5>
                                                    <span class="email">lormenyoh@gmail.com</span>
                                                </div>
                                            </div>

                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </header>
            <!-- HEADER DESKTOP-->

            <!-- MAIN CONTENT-->
            <div class="main-content">
                <div class="section__content section__content--p30">
                    <div class="container-fluid">
                        <div class="row">
                            <div class="col-md-12">
                                <div class="overview-wrap">
                                    <h2 class="title-1">Current Sensor Reading</h2>
                                    <button class="au-btn au-btn-icon au-btn--blue" type="button" data-toggle="modal"
                                        data-target="#exampleModal">
                                        <i class="zmdi zmdi-plus"></i>add item</button>
                                    <button class="au-btn au-btn-icon au-btn--blue" type="button" data-toggle="modal"
                                        data-target="#deleteModal">
                                        <i class="zmdi zmdi-minus"></i>Remove item</button>
                                    <button class="au-btn au-btn-icon au-btn--blue" type="button" data-toggle="modal"
                                        data-target="#updateModal">
                                        <i class="zmdi zmdi-plus-square"></i>Update item</button>
                                </div>
                            </div>
                        </div>
                        <div class="row m-t-25">

                                            <?php
include "config.php";

// Run the query
$q = mysqli_query($con, "select * from `simple_data`
ORDER BY  DataID DESC 
LIMIT  1");
$row = mysqli_fetch_assoc($q);
                                            echo "
                                            <div class='col-sm-6 col-lg-3'>
                                            <div class='overview-item overview-item--c1'>
                                                <div class='overview__inner'>
                                                    <div class='overview-box clearfix'>
                                                        <div class='icon mb-2' style='display:block';>
                                                            <i class='zmdi zmdi-remote-control-alt'></i>
                                                        </div>
                                                        <div class='text'>
                                                <h2>{$row['SensorName']}</h2>
                                                <span>{$row['SensorType']}</span>
                                               
                                            </div>
                                        </div>

                                    </div>
                                </div>
                            </div>
                            <div class='col-sm-6 col-lg-3'>
                                <div class='overview-item overview-item--c2'>
                                    <div class='overview__inner'>
                                        <div class='overview-box clearfix'>
                                            <div class='icon mb-2'  style='display:block';>
                                                <i class='zmdi zmdi-info'></i>
                                            </div>
                                            <div class='text'>
                                                <h2>{$row['CurrentReading']}</h2>
                                                <span>Current Reading</span>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class='col-sm-6 col-lg-3'>
                                <div class='overview-item overview-item--c3'>
                                    <div class='overview__inner'>
                                        <div class='overview-box clearfix'>
                                            <div class='icon mb-2'  style='display:block';>
                                                <i class='zmdi zmdi-pin'></i>
                                            </div>
                                            <div class='text'>
                                                <h2>{$row['SensorLocation']}</h2>
                                                <span>Sensor Location</span>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class='col-sm-6 col-lg-3'>
                                <div class='overview-item overview-item--c4'>
                                    <div class='overview__inner'>
                                        <div class='overview-box clearfix'>
                                        <div class='icon mb-2'  style='display:block';>
                                                <i class='zmdi zmdi-calendar-note'></i>
                                            </div>
                                            <div class='text'>
                                                <h2>{$row['DateRead']}</h2>
                                                <span>Date </span>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>";
?>
                                            <div class="row">
                                                <div class="col-lg-12">
                                                    <h2 class="title-1 m-b-25">Sensor Readings</h2>
                                                    <div class="table-responsive table--no-card m-b-40">
                                                        <table
                                                            class="table table-borderless table-striped table-earning">
                                                            <thead>
                                                                <tr>
                                                                    <th>Date</th>
                                                                    <th>Data ID</th>
                                                                    <th>Sensor Name</th>
                                                                    <th>Sensor Type</th>
                                                                    <th class="text-right">Reading</th>
                                                                    <th class="text-right">Sensor Location</th>

                                                                </tr>
                                                            </thead>
                                                            <tbody>
                                                                <?php

                                            include "config.php";

                                            // Run the query
                                            $q = mysqli_query($con, "select * from `simple_data`");

                                            //All echos display html elements

                                            // Fill the table body with the values
                                            while ($row = mysqli_fetch_assoc($q)) {
                                                echo "<tr>
        <td>{$row["DateRead"]}</td>
        <td>{$row["DataID"]}</td>
        <td>{$row["SensorName"]}</td>
        <td> {$row["SensorType"]}</td>
        <td> {$row["CurrentReading"]}</td>
        <td> {$row["SensorLocation"]}</td>
      
    </tr>";
                                            }

                                            ?>

                                                            </tbody>
                                                        </table>
                                                    </div>
                                                </div>

                                            </div>
                                            <div class="row">
                                                <div class="col-md-12">
                                                    <div class="copyright">
                                                        <p>Copyright © 2020 Simple Data.</p>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <!-- END MAIN CONTENT-->
                                <!-- END PAGE CONTAINER-->
                            </div>

                        </div>

                        <!-- Jquery JS-->
                        <script src="vendor/jquery-3.2.1.min.js"></script>
                        <!-- Bootstrap JS-->
                        <script src="vendor/bootstrap-4.1/popper.min.js"></script>
                        <script src="vendor/bootstrap-4.1/bootstrap.min.js"></script>
                        <!-- Vendor JS       -->
                        <script src="vendor/slick/slick.min.js">
                        </script>
                        <script src="vendor/wow/wow.min.js"></script>
                        <script src="vendor/animsition/animsition.min.js"></script>
                        <script src="vendor/bootstrap-progressbar/bootstrap-progressbar.min.js">
                        </script>
                        <script src="vendor/counter-up/jquery.waypoints.min.js"></script>
                        <script src="vendor/counter-up/jquery.counterup.min.js">
                        </script>
                        <script src="vendor/circle-progress/circle-progress.min.js"></script>
                        <script src="vendor/perfect-scrollbar/perfect-scrollbar.js"></script>
                        <script src="vendor/chartjs/Chart.bundle.min.js"></script>
                        <script src="vendor/select2/select2.min.js">
                        </script>

                        <!-- Main JS-->
                        <script src="js/main.js"></script>

</body>

</html>
<!-- end document-->