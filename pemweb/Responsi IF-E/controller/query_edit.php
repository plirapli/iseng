<?php

require_once './koneksi.php';

$id = $_GET['id'];
$title = $_POST['title'];
$genre = $_POST['genre'];

$query = "UPDATE movie 
          SET title = '$title', id_genre = '$genre' 
          WHERE id_movie = $id";

$result = mysqli_query($connection, $query);


if ($result) {
  header('Location: ../home.php');
} else {
  echo "Error: " . mysqli_error($connection);
}
