<?php

require 'connection.php';

$username = $_POST["username"];
$password = $_POST["password"];
$conf_password = $_POST["confirm_password"];


// Query Data dari TB user (SELECT ALL)
$query_check = "SELECT * FROM user WHERE `username` = '$username'";
$check_result = mysqli_num_rows(mysqli_query($connection, $query_check));

// Cek username dah ada atau belum
if ($check_result === 0) {
  // Cek password yang ditulis sama kaya confirm password ga
  if ($password === $conf_password) {
    $query_insert = "INSERT INTO user VALUES( '', '$username', '$password' )";
    $result = mysqli_query($connection, $query_insert);

    if ($result) {
      header("Location: ../index.php?pesan=register_success");
      exit;
    }
  } else {
    header("Location: ../register.php?pesan=password_beda");
    exit;
  }
} else {
  header("Location: ../register.php?pesan=username_ada");
  exit;
}
