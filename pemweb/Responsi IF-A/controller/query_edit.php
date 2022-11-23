<?php

require_once './koneksi.php';

$nim = $_GET['nim'];
$nama = $_POST['nama'];
$fakultas = $_POST['fakultas'];
$angkatan = $_POST['angkatan'];

$query = "UPDATE data 
          SET nama = '$nama', fakultas = '$fakultas', angkatan = '$angkatan'
          WHERE nim = '$nim'";
$result = mysqli_query($connection, $query);

if ($result) {
  header("Location: ../read_mhs.php");
} else {
  echo "Error: " . mysqli_error($connection);
}
