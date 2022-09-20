<?php

// Konek ke DB
$connection =  mysqli_connect('localhost', 'rafli', '123', 'latihan_php');

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
  $jurusan = htmlspecialchars($data["jurusan"]);

  // Query (INSERT DATA)
  $query = "INSERT INTO mahasiswa VALUES(
    '', '$nama', '$nim', '$jurusan'
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
