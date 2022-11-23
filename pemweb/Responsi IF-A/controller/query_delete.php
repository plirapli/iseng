<?php

require_once './koneksi.php';

$nim = $_GET["nim"];
$query = "DELETE FROM data WHERE nim = $nim";
$result = mysqli_query($connection, $query);

if ($result) {
  header("Location: ../read_mhs.php");
} else {
  echo "Error: " . mysqli_error($connection);
}
