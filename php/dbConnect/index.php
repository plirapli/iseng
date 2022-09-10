<?php

require 'functions.php';

$mahasiswa = query("SELECT * FROM mahasiswa");

// Cek tombol submit pada form daftar dah ditekan/belum
if (isset($_POST["submit"])) {
  if (tambah($_POST) > 0) {
    header("Location: " . 'index.php');
  } else {
    echo "Failed";
  }
}

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
      padding: 0.5rem;
      margin: 0;
      text-align: center;
    }

    td>button {
      width: 100%;
    }
  </style>
</head>

<body>
  <form action="index.php" method="POST">
    <table>
      <tr>
        <td colspan="2">
          <p>Daftar Mahasiswa Baru</p>
        </td>
      </tr>
      <tr>
        <td>
          <label for="nim">NIM</label>
        </td>
        <td>
          <input type="text" name="nim" id="nim" required>
        </td>
      </tr>
      <tr>
        <td>
          <label for="nama">Nama</label>
        </td>
        <td>
          <input type="text" name="nama" id="nama" required>
        </td>
      </tr>
      <tr>
        <td>
          <label for="nama">Jurusan</label>
        </td>
        <td>
          <input type="text" name="jurusan" id="jurusan" required>
        </td>
      </tr>
      <tr>
        <td colspan="2">
          <button type="submit" name="submit">Tambah</button>
        </td>
      </tr>
  </form>
  </table>

  <br>

  <table>
    <thead>
      <tr>
        <td colspan="5">
          <p>Daftar Mahasiswa</p>
        </td>
      </tr>
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