<?php

require 'functions.php';

// Buat Read TB
$mahasiswa = query("SELECT * FROM mahasiswa");

// Buat Create Data
// Cek tombol submit pada form daftar dah ditekan/belum
if (isset($_POST["submit"])) {
  if (tambah($_POST) > 0) {
    header("Location: " . 'index.php');
  } else {
    echo "Failed";
  }
}

// Buat Hapus Data
// Cek apakah tombol "hapus" dah diklik/belum
if (isset($_GET["id"])) {
  if (hapus($_GET["id"]) > 0) {
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
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

  <style>

  </style>
</head>

<body>
  <div class="p-5 pb-0">
    <h4 class="mb-3">Daftar Mahasiswa</h4>
    <form action="index.php" method="POST">
      <div class="mb-3">
        <label for="inputNim" class="form-label">NIM</label>
        <input type="number" class="form-control" id="inputNim" name="nim" placeholder="123210078">
      </div>
      <div class="mb-3">
        <label for="inputNama" class="form-label">Nama</label>
        <input type="text" class="form-control" id="inputNama" name="nama" placeholder="Muhammad Rafli">
      </div>
      <div class="mb-3">
        <label for="inputAngkatan" class="form-label">Angkatan</label>
        <input type="text" class="form-control" id="inputAngkatan" name="angkatan" placeholder="2021">
      </div>
      <div class="mb-3">
        <label for="inputSks" class="form-label">SKS</label>
        <input type="text" class="form-control" id="inoutSks" name="sks" placeholder="24">
      </div>
      <button type="submit" name="submit" class="btn btn-primary w-100">Tambah</button>
    </form>
  </div>

  <div class="p-5 pt-0 mt-4">
    <h4>Daftar Mahasiswa</h4>
    <table class="table">
      <thead>
        <tr>
          <th scope="col">#</th>
          <th scope="col">NIM</th>
          <th scope="col">Nama</th>
          <th scope="col">Angaktan</th>
          <th scope="col">SKS</th>
          <th scope="col">Aksi</th>
        </tr>
      </thead>
      <tbody>
        <?php $no = 1; ?>
        <?php foreach ($mahasiswa as $mhs) : ?>
          <tr>
            <th scope="row"><?= $no++; ?>.</th>
            <td><?= $mhs["nim"]; ?></td>
            <td><?= $mhs["nama"]; ?></td>
            <td><?= $mhs["angkatan"]; ?></td>
            <td><?= $mhs["sks"]; ?></td>
            <td>
              <a href="edit.php?id=<?= $mhs["id"] ?>">Ubah</a>
              <a href="index.php?id=<?= $mhs["id"] ?>">Hapus</a>
            </td>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>