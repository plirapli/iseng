<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Home</title>
  <link rel="shortcut icon" href="../assets/favicon/home.svg" type="image/x-icon">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous" />
  <link rel="stylesheet" href="../assets/style.css" />
</head>

<body>
  <!-- NAVBAR -->
  <nav class="navbar nav-brand">
    <div class="container-fluid p-2 px-3">
      <a class="navbar-brand d-flex align-items-center" href="/">
        <span class="navbar-brand mb-0 h1 nav-brand-text">
          Praktikum IF
          <span class="text-block-custom">
            123210078
          </span>
        </span>
      </a>
      <a class="nav-link text-white-50 d-flex align-items" href="../index.php">
        <iconify-icon icon="heroicons-solid:logout" width="24"></iconify-icon>
        <span class="ms-2">Keluar</span>
      </a>
    </div>
  </nav>
  <!-- NAVBAR END -->

  <main class="main-container main flex-column">
    <p class="mb-2">Selamat datang di</p>
    <h2 class="welcome">Praktikum Informatika</h2>
    <div class="mt-3 w-100 container">
      <div class="row">
        <a class="text-black col" href="lab.php">
          <button class="w-100 btn btn-black">Lab</button>
        </a>
        <a class="text-black col" href="lab.php">
          <button class="w-100 btn btn-black">Waktu Praktikumn</button>
        </a>
      </div>
      <div class="mt-3 row">
        <a class="text-black col" href="jadwal.php">
          <button class="w-100 btn btn-black">Jadwal Praktikum</button>
        </a>
      </div>
    </div>
  </main>
  <footer class="px-4 py-3 text-center"></footer>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
  <script>
    // Buat Tahun di footer doang
    document.querySelector('footer').innerHTML =
      '&copy; Copyright ' + new Date().getFullYear() + ' Muhammad Rafli';
  </script>
</body>

</html>