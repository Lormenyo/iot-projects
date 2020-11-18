<?php


function function_alert($msg) {
    echo "<script type='text/javascript'>alert('$msg');</script>";
}

function redirectToHome() {
    echo "<script type='text/javascript'>location.href = 'index.php';</script>";
}
?>