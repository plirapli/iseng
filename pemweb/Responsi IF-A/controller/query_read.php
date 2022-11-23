<?php

require_once 'koneksi.php';

function select_data_id()
{
  global $connection;

  $nim = $_GET['nim'];
  $query = "SELECT * FROM data 
            INNER JOIN fakultas ON data.fakultas = fakultas.id_fakultas
            WHERE nim = $nim";
  $result = mysqli_query($connection, $query);

  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  return $rows[0];
}

function select_fakultas()
{
  global $connection;

  $query = "SELECT * FROM fakultas";
  $result = mysqli_query($connection, $query);

  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  return $rows;
}
