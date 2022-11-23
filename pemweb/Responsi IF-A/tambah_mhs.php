<?php

session_start();
require_once './controller/query_read.php';

if (!isset($_SESSION['username'])) {
  header("Location: index.php?pesan=belum_login");
}

$fakultas = select_fakultas();

?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Home</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body class="min-vh-100 d-flex flex-column">
  <nav class="navbar navbar-expand-lg bg-light">
    <div class="container-fluid">
      <a class="navbar-brand" href="#">
        <img src="/docs/5.2/assets/brand/bootstrap-logo.svg" alt="Logo" width="30" height="24" class="d-inline-block align-text-top">
        Data Center
      </a>

      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>

      <div class="collapse navbar-collapse justify-content-end" id="navbarNavDropdown">
        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link" aria-current="page" href="home.php">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link active" href="tambah_mhs.php">Tambah Data</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="read_mhs.php">Data Mahasiswa</a>
          </li>
          <li class="nav-item dropdown">
            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
              Kategori
            </a>
            <ul class="dropdown-menu dropdown-menu-end">
              <?php foreach ($fakultas as $fak) : ?>
                <li>
                  <a class="dropdown-item" href="read_mhs.php?fak=<?= $fak['id_fakultas'] ?>">
                    <?= $fak["fakultas"]; ?>
                  </a>
                </li>
              <?php endforeach; ?>
            </ul>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="./controller/logout.php">Logout</a>
          </li>
        </ul>
      </div>
    </div>
  </nav>

  <div class="container col-md-6 py-4">
    <h2 class="mb-4 text-center">Input Data Mahasiswa Baru</h2>
    <div class="p-5 bg-light rounded-3">
      <form action="./controller/add_data.php" method="POST">
        <h2>Form</h2>
        <div class="row mb-3">
          <label for="inputNIM" class="fw-bold col-sm-2 col-form-label">NIM</label>
          <div class="col-sm-10">
            <input type="text" class="form-control" name="nim" id="inputNIM" placeholder="NIM">
          </div>
        </div>
        <div class="row mb-3">
          <label for="inputNama" class="fw-bold col-sm-2 col-form-label">Nama</label>
          <div class="col-sm-10">
            <input type="text" class="form-control" name="nama" id="inputNama" placeholder="Nama Lengkap">
          </div>
        </div>
        <div class="row mb-3">
          <label class="fw-bold col-sm-2 col-form-label">Fakultas</label>
          <div class="col-sm-10">
            <select name="fakultas" class="form-select">
              <option selected>Choose</option>
              <?php foreach ($fakultas as $fak) : ?>
                <option value="<?= $fak["id_fakultas"] ?>">
                  <?= $fak["fakultas"] ?>
                </option>
              <?php endforeach ?>
            </select>
          </div>
        </div>
        <div class="row mb-3 align-items-center">
          <label for="inputNIM" class="fw-bold col-sm-2 col-form-label">NIM</label>
          <div class="col-sm-10">
            <div class="form-check form-check-inline">
              <input class="form-check-input" type="radio" name="angkatan" id="2019" value="2019">
              <label class="form-check-label" for="2019">
                2019
              </label>
            </div>
            <div class="form-check form-check-inline">
              <input class="form-check-input" type="radio" name="angkatan" id="2020" value="2020">
              <label class="form-check-label" for="2020">
                2020
              </label>
            </div>
            <div class="form-check form-check-inline">
              <input class="form-check-input" type="radio" name="angkatan" id="2021" value="2021">
              <label class="form-check-label" for="2021">
                2021
              </label>
            </div>
          </div>
        </div>
        <button type="submit" class="btn btn-primary">Tambah Data</button>
      </form>
    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>