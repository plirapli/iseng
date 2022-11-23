<?php

require 'koneksi.php';

function read_genres()
{
  global $connection;

  $query = 'SELECT * FROM genre';
  $result = mysqli_query($connection, $query);

  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  return $rows;
}

function read_movies()
{
  global $connection;

  $query = 'SELECT * FROM movie INNER JOIN genre ON movie.id_genre = genre.id_genre';
  $result = mysqli_query($connection, $query);

  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  return $rows;
}

function read_movies_id($id)
{
  global $connection;

  $query = "SELECT * FROM movie INNER JOIN genre ON movie.id_genre = genre.id_genre WHERE id_movie = $id";
  $result = mysqli_query($connection, $query);

  $rows = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $rows[] = $row;
  }

  return $rows[0];
}
