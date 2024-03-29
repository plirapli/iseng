<?php

session_start();

if (!isset($_SESSION["login"])) {
  header("Location: index.php?pesan=belum_login");
  exit;
}

require 'utils/query_waktu.php';

// Buat Read Table
$waktu_praktikum = select_all_waktu();

// Buat Create Data
// Cek tombol submit pada form daftar dah ditekan/belum
if (isset($_POST["submit"])) {
  if (add_waktu($_POST) > 0) {
    header("Location: waktu.php");
  } else {
    echo "Failed";
  }
}

// Buat Hapus Data
// Cek apakah tombol "hapus" dah diklik/belum
if (isset($_GET["id"])) {
  if (delete_waktu($_GET["id"]) > 0) {
    header("Location: waktu.php");
  } else {
    echo "Failed";
  }
}

?>

<!DOCTYPE html>
<html lang="id">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Waktu</title>
  <link rel="shortcut icon" href="../assets/favicon/home.svg" type="image/x-icon">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous" />
  <link rel="stylesheet" href="./assets/style.css" />
</head>

<body>
  <!-- NAVBAR -->
  <nav class="navbar nav-brand">
    <div class="container-fluid p-2 px-3">
      <a class="navbar-brand d-flex align-items-center" href="home.php">
        <span class="navbar-brand mb-0 h1 nav-brand-text">
          Praktikum IF
          <span class="text-block-custom">
            123210078
          </span>
        </span>
      </a>
      <a class="nav-link text-white-50 d-flex align-items" href="./utils/logout.php">
        <iconify-icon icon="heroicons-solid:logout" width="24"></iconify-icon>
        <span class="ms-2">Keluar</span>
      </a>
    </div>
  </nav>
  <nav class="navbar navbar-expand-lg nav-bg-custom">
    <div class="container-fluid">
      <div class="dropdown-custom">
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
      </div>
      <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
        <div class="navbar-nav">
          <a class="nav-link nav-text nav-custom nav-home" aria-current="page" href="home.php">
            <iconify-icon icon="bx:home-alt-2" width="18"></iconify-icon>
            Home
          </a>
          <a class="nav-link nav-text nav-custom" href="lab.php">
            <iconify-icon icon="carbon:chemistry" width="18"></iconify-icon>
            Lab
          </a>
          <a class="nav-link active nav-text nav-custom" href="waktu.php">
            <iconify-icon icon="bx:time-five" width="18"></iconify-icon>
            Waktu
          </a>
          <a class="nav-link nav-text nav-custom" href="jadwal.php">
            <iconify-icon icon="bx:calendar" width="18"></iconify-icon>
            Jadwal
          </a>
        </div>
      </div>
    </div>
  </nav>
  <!-- NAVBAR END -->

  <main class="mt-2 container">
    <div class="row gap-2 flex-col-reverse">
      <section class="col-lg">
        <h2>Waktu Praktikum</h2>
        <table class="table">
          <thead>
            <tr>
              <th class="text-center" scope="col">No.</th>
              <th class="text-center" scope="col">Waktu</th>
              <th class="text-center" scope="col">Aksi</th>
            </tr>
          </thead>
          <tbody>
            <?php $no = 1; ?>
            <?php foreach ($waktu_praktikum as $waktu) : ?>
              <tr>
                <th class=" text-center" scope="row"><?= $no++; ?>.</th>
                <td class="text-center">
                  <?= $waktu["mulai"]; ?>
                  -
                  <?= $waktu["selesai"]; ?>
                </td>
                <td class="text-center">
                  <a class="btn btn-danger pb-0 px-2" href="waktu.php?id=<?= $waktu["id"] ?>">
                    <iconify-icon icon="bx:trash" width="24"></iconify-icon>
                  </a>
                </td>
              </tr>
            <?php endforeach; ?>
          </tbody>
        </table>
      </section>
      <section class="col-lg-5 container-custom">
        <h3 class="mb-3 h-custom">Waktu Praktikum</h3>
        <form action="waktu.php" method="POST">
          <div class="row">
            <div class="mb-3 col">
              <label for="inputMulai" class="form-label">Mulai</label>
              <div class="form-custom">
                <iconify-icon icon="carbon:chemistry" width="20"></iconify-icon>
                <input class="w-100" type="time" name="mulai" id="inputMulai" placeholder="Masukkan nama lab" required>
              </div>
            </div>
            <div class="mb-3 col">
              <label for="inputSelesai" class="form-label">Selesai</label>
              <div class="form-custom">
                <iconify-icon icon="carbon:chemistry" width="20"></iconify-icon>
                <input class="w-100" type="time" name="selesai" id="inputSelesai" placeholder="Masukkan nama lab" required>
              </div>
            </div>
          </div>
          <button type="submit" name="submit" class="btn btn-black w-100">Daftar</button>
        </form>
      </section>
    </div>
  </main>
  <footer class="px-4 py-3 fw text-center"></footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
  <script>
    // Buat Tahun di footer doang
    document.querySelector('footer').innerHTML =
      '&copy; Copyright ' + new Date().getFullYear() + ' Muhammad Rafli';
  </script>
</body>

</html>