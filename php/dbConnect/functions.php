<?php

// Konek ke DB
$connection =  mysqli_connect('localhost', 'rafli', '123', 'latihan_php');

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
