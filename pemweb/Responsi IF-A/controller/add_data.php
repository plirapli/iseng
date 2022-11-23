<?php

require_once './koneksi.php';

$nim = $_POST['nim'];
$nama = $_POST['nama'];
$fakultas = $_POST['fakultas'];
$angkatan = $_POST['angkatan'];

$query = "INSERT INTO data 
          VALUES( '$nim', '$nama', '$fakultas', '$angkatan' )";
$result = mysqli_query($connection, $query);

if ($result) {
  header("Location: ../read_mhs.php");
} else {
  echo "Error: " . mysqli_error($connection);
}
