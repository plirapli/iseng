<?php

require 'connection.php';

// Select All Data
function select_all_jadwal()
{
  global $connection;

  // Query Data dari TB mahasiswa (SELECT ALL)
  $query =
    "SELECT j.id, mata_kuliah, program_studi, 
     lab.id AS id_lab, lab.nama AS nama_lab, 
     waktu.id AS id_waktu, waktu.mulai AS waktu_mulai, waktu.selesai AS waktu_selesai
     FROM jadwal as j 
     INNER JOIN lab ON j.id_lab = lab.id 
     INNER JOIN waktu ON j.id_waktu = waktu.id";
  $result = mysqli_query($connection, $query);

  // Memasukkan hasil query ke dalam var rows
  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  // Mereturn var rows
  return $rows;
}

function add_jadwal($data)
{
  global $connection;

  $mk = htmlspecialchars($data["matkul"]);
  $prodi = htmlspecialchars($data["prodi"]);
  $lab = htmlspecialchars($data["lab"]);
  $waktu = htmlspecialchars($data["waktu"]);

  // Query (INSERT DATA)
  $query = "INSERT INTO jadwal VALUES( '', '$mk', '$prodi', '$lab', '$waktu' )";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

function edit_jadwal($data)
{
  global $connection;

  $id = $data["id"];
  $mk = htmlspecialchars($data["matkul"]);
  $prodi = htmlspecialchars($data["prodi"]);
  $lab = htmlspecialchars($data["lab"]);
  $waktu = htmlspecialchars($data["waktu"]);

  // Query (EDIT DATA)
  $query = "UPDATE jadwal SET mata_kuliah = '$mk', program_studi = '$prodi', id_lab = '$lab', id_waktu = '$waktu' WHERE id = $id";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

function delete_jadwal($id)
{
  global $connection;

  // Query (DELETE DATA)
  $query = "DELETE FROM jadwal WHERE id='$id'";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}
