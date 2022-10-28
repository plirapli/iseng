<?php

require 'functions.php';

$prev_file_name = "index.php";

// Cek apakah data dah ada/belum
if (!isset($_GET["id"])) {
  header("Location: " . $prev_file_name);
  exit;
} else {
  $mahasiswa = bacaId($_GET["id"]);
}

// Buat Edit Data
// Cek tombol submit pada form edit dah diklik/belum
if (isset($_POST["submit"])) {
  if (edit($_GET['id'], $_POST) > 0) {
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
</head>

<body>
  <div class="p-5 pb-0">
    <h4 class="mb-3">Daftar Mahasiswa</h4>
    <form action="index.php" method="POST">
      <div class="mb-3">
        <label for="inputNim" class="form-label">NIM</label>
        <input type="number" class="form-control" id="inputNim" name="nim" value=<?= $mahasiswa[0]["nim"] ?> placeholder="123210078">
      </div>
      <div class="mb-3">
        <label for="inputNama" class="form-label">Nama</label>
        <input type="text" class="form-control" id="inputNama" name="nama" value="<?= $mahasiswa[0]['nama'] ?>" placeholder="Nama">
      </div>
      <div class="mb-3">
        <label for="inputAngkatan" class="form-label">Angkatan</label>
        <input type="text" class="form-control" id="inputAngkatan" name="angkatan" value=<?= $mahasiswa[0]["angkatan"] ?> placeholder="2021">
      </div>
      <div class="mb-3">
        <label for="inputSks" class="form-label">SKS</label>
        <input type="text" class="form-control" id="inoutSks" name="sks" value=<?= $mahasiswa[0]["sks"] ?> placeholder="24">
      </div>
      <button type="submit" name="submit" class="btn btn-primary w-100">Edit</button>
      <a href="index.php" class="w-100 mt-2 btn btn-secondary">Kembali</a>
    </form>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>