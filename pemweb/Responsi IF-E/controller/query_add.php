<?php

require_once './koneksi.php';

$title = $_POST['title'];
$genre = $_POST['genre'];

$query = "INSERT INTO movie VALUES('', '$title', '$genre')";
$result = mysqli_query($connection, $query);

if ($result) {
  header('Location: ../home.php');
} else {
  echo "Error: " . mysqli_error($connection);
}
