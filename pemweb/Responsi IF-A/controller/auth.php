<?php

session_start();
require_once './koneksi.php';

$username = $_POST['username'];
$password = $_POST['password'];

$query = "SELECT * FROM petugas 
          WHERE username = '$username' AND password = '$password'";
$result = mysqli_query($connection, $query);

if (mysqli_num_rows($result) == 1) {
  $nama = mysqli_fetch_assoc($result)["nama"];

  $_SESSION["username"] = $username;
  $_SESSION["nama"] = $nama;

  header("Location: ../home.php");
} else {
  header("Location: ../index.php?pesan=login_gagal");
}
