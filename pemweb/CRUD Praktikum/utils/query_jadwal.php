<?php

require 'connection.php';

// Select All Data
function select_all_jadwal()
{
  global $connection;

  // Query Data dari TB mahasiswa (SELECT ALL)
  $query =
    "SELECT j.id, mata_kuliah, program_studi, 
     lab.nama AS nama_lab, waktu.mulai AS waktu_mulai, waktu.selesai AS waktu_selesai
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

  $nama = htmlspecialchars($data["nama"]);
  $prodi = htmlspecialchars($data["prodi"]);
  $lab = htmlspecialchars($data["lab"]);
  $waktu = htmlspecialchars($data["waktu"]);

  // Query (INSERT DATA)
  $query = "INSERT INTO jadwal VALUES( '', '$nama', '$prodi', '$lab', '$waktu' )";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

// function delete($id)
// {
//   global $connection;

//   // Query (INSERT DATA)
//   $query = "DELETE FROM lab WHERE id='$id'";
//   mysqli_query($connection, $query);

//   return mysqli_affected_rows($connection);
// }
