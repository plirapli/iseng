<?php

session_start();
require 'connection.php';

$username = $_POST["username"];
$password = $_POST["password"];

// Query Data dari TB user (SELECT ALL)
$query = "SELECT * FROM user WHERE `username` = '$username' AND `password` = '$password'";
$result = mysqli_query($connection, $query);


// Cek Username
if (mysqli_num_rows($result) === 1) {
  $_SESSION["login"] = true;
  header("Location: ../index.php");
  exit;
}

header("Location: ../login.php?pesan=input_salah");
exit;
