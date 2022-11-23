<?php

session_start();
require 'koneksi.php';

$username = $_POST["username"];
$password = $_POST["password"];

$query = "SELECT * FROM user 
          WHERE username = '$username' AND password = '$password'";
$result = mysqli_query($connection, $query);
$isFound = mysqli_num_rows($result);

if ($isFound === 1) {
  $_SESSION["username"] = $username;
  header('Location: ../home.php');
} else {
  header('Location: ../index.php?pesan=login_gagal');
}
