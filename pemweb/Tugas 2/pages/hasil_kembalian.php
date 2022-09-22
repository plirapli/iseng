<?php

// Buat nyimpen lembar pecahan
$lembar = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
$pecahan = [100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100];

// Hasil input user
$harga = $_GET["harga"];
$uang = $_GET["uang"];

$kembalian;


function kembalian($harga, $uang)
{
  global $pecahan, $lembar, $kembalian;

  $kembalian = $uang - $harga;

  if ($kembalian >= 0) {
    for ($i = 0; $i < count($pecahan); $i++) {
      if ($kembalian - $pecahan[$i] >= 0) {
        $kembalian -= $pecahan[$i];
        $lembar[$i]++;
        $i--;
      }
    }
  } else {
    for ($i = 0; $i < count($pecahan); $i++) {
      if ($kembalian + $pecahan[$i] <= 0) {
        $kembalian += $pecahan[$i];
        $lembar[$i]++;
        $i--;
      }
    }
    $kembalian = 0;
  }
};

kembalian($_GET["harga"], $_GET["uang"]);

$total = [$lembar, $pecahan];

?>


<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous" />
  <link rel="stylesheet" href="../assets/style.css" />
</head>

<body>
  <!-- NAVBAR -->
  <nav class="navbar nav-brand">
    <div class="container-fluid p-2 px-3">
      <a class="navbar-brand d-flex align-items-center" href="/">
        <span class="ms-3 navbar-brand mb-0 h1 nav-brand-text">
          Tugas Web PHP
          <span class="text-block-custom">
            123210078
          </span>
        </span>
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
          <a class="nav-link nav-text nav-custom" href="gatau.php">
            <iconify-icon icon="bx:math" width="18"></iconify-icon>
            Gatau
          </a>
          <a class="nav-link active nav-text nav-custom" href="kembalian.php">
            <iconify-icon icon="bx:money-withdraw" width="18"></iconify-icon>
            Kembalian
          </a>
          <a class="nav-link nav-text nav-custom" href="../index.php">
            <iconify-icon icon="heroicons-solid:logout" width="18"></iconify-icon> Keluar
          </a>
        </div>
      </div>
    </div>
  </nav>
  <!-- NAVBAR END -->

  <main class="main pt-2">
    <h3 class="mb-4 fw-bold">
      Hasil Kembalian &nbsp;💰
    </h3>
    <div class="flex-card">
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-2">
          <iconify-icon icon="akar-icons:money" width="24"></iconify-icon>
          Uang
        </div>
        <h3 class="fw-bold">Rp <?= $uang; ?></h3>
      </div>
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-2">
          <iconify-icon icon="ic:outline-price-change" width="24"></iconify-icon>
          Harga
        </div>
        <h3 class="fw-bold">Rp <?= $harga; ?></h2>
      </div>
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-2">
          <iconify-icon icon="material-symbols:change-circle-outline-rounded" width="24"></iconify-icon>
          <?php
          if ($uang - $harga >= 0)
            echo "Kembalian";
          else
            echo "Hutang";
          ?>
        </div>
        <h3 class="fw-bold">Rp <?= $uang - $harga; ?></h3>
      </div>
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-2">
          <iconify-icon icon="bx:donate-heart" width="24"></iconify-icon>
          Donasi
        </div>
        <h3 class="fw-bold">Rp <?= $kembalian; ?></h3>
      </div>
    </div>
    <div class="mt-5 container-custom p-2 table-custom">
      <table>
        <thead>
          <tr>
            <th class="p-2 text-center">Pecahan</th>
            <th class="p-2 px-4">Lembar</th>
          </tr>
        </thead>
        <tbody">
          <?php foreach ($total[0] as $key => $value) : ?>
            <tr>
              <td class="px-4 pb-2 pt-0 d-flex justify-content-between gap-3">
                Rp
                <span class="text-end">
                  <?= $total[1][$key] ?>
                </span>
              </td>
              <td class="px-4 pb-2 pt-0 text-center">
                <?php
                if ($total[0][$key]) {
                  echo '<span class="fw-bold">' . $total[0][$key] . '</span>';
                } else {
                  echo $total[0][$key];
                }
                ?>
              </td>
            </tr>
          <?php endforeach; ?>
          </tbody>
      </table>
    </div>
  </main>
  <footer class="px-4 py-3 fw-bold text-center">
    &copy; Copyright 2022 Muhammad Rafli
  </footer>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
</body>

</html>