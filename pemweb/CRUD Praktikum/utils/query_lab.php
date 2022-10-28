<?php

require 'connection.php';

// Select All Data
function selectAll()
{
  global $connection;

  // Query Data dari TB mahasiswa (SELECT ALL)
  $query = "SELECT * FROM lab";
  $result = mysqli_query($connection, $query);

  // Memasukkan hasil query ke dalam var rows
  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  // Mereturn var rows
  return $rows;
}

function add($data)
{
  global $connection;

  $nama = htmlspecialchars($data["nama"]);

  // Query (INSERT DATA)
  $query = "INSERT INTO lab VALUES( '', '$nama' )";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}

function delete($id)
{
  global $connection;

  // Query (INSERT DATA)
  $query = "DELETE FROM lab WHERE id='$id'";
  mysqli_query($connection, $query);

  return mysqli_affected_rows($connection);
}
