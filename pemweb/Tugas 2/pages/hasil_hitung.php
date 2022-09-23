<?php

// Hasil input user
$angka_1 = $_GET["angka_pertama"];
$angka_2 = $_GET["angka_kedua"];

function kpk($a, $b)
{
  $kpk = 0;

  for ($i = 1; $i <= $b; $i++) {
    $kpk += $a;
    if ($kpk % $b == 0)
      break;
  }

  return $kpk;
}

function fpb($a, $b)
{
  $r = $a % $b;

  while ($r != 0) {
    $a = $b;
    $b = $r;
    $r = $a % $b;
  }

  return $b;
}

$total = [kpk($angka_1, $angka_2), fpb($angka_1, $angka_2)];

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
          <a class="nav-link nav-text nav-custom" href="form.php">
            <iconify-icon icon="icon-park:form-one" width="18"></iconify-icon>
            Form
          </a>
          <a class="nav-link active nav-text nav-custom" href="kpk_dan_fpb.php">
            <iconify-icon icon="bx:math" width="18"></iconify-icon>
            KPK dan FPB
          </a>
          <a class="nav-link nav-text nav-custom" href="kembalian.php">
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
      Hasil Perhitungan &nbsp;🧮
    </h3>
    <div class="flex-card">
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-1">
          <iconify-icon icon="tabler:square-number-1" width="24"></iconify-icon>
          Angka Ke-1
        </div>
        <h3 class="fw-bold"><?= $angka_1; ?></h3>
      </div>
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-1">
          <iconify-icon icon="tabler:square-number-2" width="24"></iconify-icon>
          Angka Ke-2
        </div>
        <h3 class="fw-bold"><?= $angka_2; ?></h2>
      </div>
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-1">
          <iconify-icon icon="fluent:math-symbols-16-regular" width="24"></iconify-icon>
          KPK
        </div>
        <h3 class="fw-bold"><?= $total[0]; ?></h2>
      </div>
      <div class="container-custom me-0">
        <div class="mb-1 d-flex align-items-center gap-1">
          <iconify-icon icon="fluent:math-symbols-16-regular" width="24"></iconify-icon>
          FPB
        </div>
        <h3 class="fw-bold"><?= $total[1]; ?></h2>
      </div>
    </div>
  </main>
  <footer class="px-4 py-3 fw-bold text-center">
    &copy; Copyright 2022 Muhammad Rafli
  </footer>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
</body>

</html>