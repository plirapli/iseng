<?php

require 'connection.php';

// Query Data dari TB user (SELECT ALL)
$query = "SELECT * FROM user";
$result = mysqli_query($connection, $query);

// Memasukkan hasil query ke dalam var rows
$users = [];
while ($user = mysqli_fetch_assoc($result)) {
  $users[] = $user;
}

$is_found = 0;

function check($usn, $pwd)
{
  $in_usn = $_POST["username"];
  $in_pwd = $_POST["pwd"];

  return $in_usn == $usn && $in_pwd == $pwd ? 1 : 0;
}

for ($i = 0; $i < count($users); $i++) {
  global $is_found;

  $username = $users[$i]["username"];
  $password = $users[$i]["password"];

  if (check($username, $password) == 1) {
    header("Location: ../pages/home.php");
    $is_found = 1;
    break;
  }
}

if ($is_found == 0) {
  header("Location: ../index.php?isGagal=true");
}
