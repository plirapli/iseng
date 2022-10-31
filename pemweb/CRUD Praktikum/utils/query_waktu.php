<?php

require 'connection.php';

// Select All Data
function select_all_waktu()
{
  global $connection;

  // Query Data dari TB mahasiswa (SELECT ALL)
  $query = "SELECT * FROM waktu";
  $result = mysqli_query($connection, $query);

  // Memasukkan hasil query ke dalam var rows
  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  // Mereturn var rows
  return $rows;
}

function add_waktu($data)
{
  global $connection;

  $mulai = htmlspecialchars($data["mulai"]);
  $selesai = htmlspecialchars($data["selesai"]);

  // Query (INSERT DATA)
  $query = "INSERT INTO waktu VALUES( '', '$mulai', '$selesai' )";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

function delete_waktu($id)
{
  global $connection;

  // Query (INSERT DATA)
  $query = "DELETE FROM waktu WHERE id='$id'";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}
