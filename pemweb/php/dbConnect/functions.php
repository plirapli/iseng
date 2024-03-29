<?php

// Konek ke DB
// $username = $_ENV["DATABASE_USERNAME"];
// $passwd = $_ENV["DATABASE_PASSWORD"];
// $db_name = $_ENV["DATABASE_NAME"];

$username = "rafli";
$passwd = "123";
$db_name = "praktikum_mhs";

$connection =  mysqli_connect('localhost', $username, $passwd, $db_name);

// Select All Data
function query($query)
{
  global $connection;

  // Query Data dari TB mahasiswa (SELECT ALL)
  $result = mysqli_query($connection, $query);

  // Memasukkan hasil query ke dalam var rows
  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  // Mereturn var rows
  return $rows;
}

// Tambah Data
function tambah($data)
{
  global $connection;

  $nim = htmlspecialchars($data["nim"]);
  $nama = htmlspecialchars($data["nama"]);
  $angkatan = htmlspecialchars($data["angkatan"]);
  $sks = htmlspecialchars($data["sks"]);
  // $jurusan = htmlspecialchars($data["jurusan"]);

  // Query (INSERT DATA)
  $query = "INSERT INTO mahasiswa VALUES(
    '', '$nim', '$nama', '$angkatan', '$sks'
  )";

  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

// Hapus Data
function hapus($id)
{
  global $connection;

  $query = "DELETE FROM mahasiswa WHERE id = $id";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

function bacaId($id)
{
  global $connection;

  $query = "SELECT * FROM mahasiswa WHERE id = $id";
  $result = mysqli_query($connection, $query);

  // Memasukkan hasil query ke dalam var rows
  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  // Mereturn var rows
  return $rows;
}


// Edit Dta
function edit($id, $data)
{
  global $connection;

  $nim = htmlspecialchars($data["nim"]);
  $nama = htmlspecialchars($data["nama"]);
  $angkatan = htmlspecialchars($data["angkatan"]);
  $sks = htmlspecialchars($data["sks"]);

  $query = "UPDATE mahasiswa SET nim = '$nim', nama = '$nama', angkatan = '$angkatan', sks = '$sks' WHERE id = $id";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}
