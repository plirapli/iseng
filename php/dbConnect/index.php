<?php

require 'functions.php';

$mahasiswa = query("SELECT * FROM mahasiswa");

?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

  <style>
    table {
      border-spacing: 0;
      border: 2px solid black;
    }

    th,
    td {
      padding: 1rem;
      margin: 0;
      text-align: center;
    }
  </style>
</head>

<body>
  <table>
    <thead>
      <tr>
        <th>No.</th>
        <th>NIM</th>
        <th>Nama</th>
        <th>Jurusan</th>
        <th>Aksi</th>
      </tr>
    </thead>
    <tbody>
      <?php $no = 1; ?>
      <?php foreach ($mahasiswa as $mhs) : ?>
        <tr>
          <td><?= $no++; ?>.</td>
          <td><?= $mhs["nim"]; ?></td>
          <td><?= $mhs["nama"]; ?></td>
          <td><?= $mhs["jurusan"]; ?></td>
          <td>
            <a href="">Ubah</a>
            <a href="">Hapus</a>
          </td>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
</body>

</html>