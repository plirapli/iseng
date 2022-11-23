<?php

require 'koneksi.php';

$id = $_GET["id"];

$query = "DELETE FROM movie WHERE id_movie = $id";
$result = mysqli_query($connection, $query);

if ($result) {
  header('Location: ../home.php');
} else {
  echo "Error: " . mysqli_error($connection);
}
