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
          <a class="nav-link active nav-text nav-custom" href="form.php">
            <iconify-icon icon="icon-park:form-one" width="18"></iconify-icon>
            Form
          </a>
          <a class="nav-link nav-text nav-custom" href="kpk_dan_fpb.php">
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

  <main class="main">
    <div class="container-custom">
      <h3 class="mb-3 h-custom">Form 📝</h3>
      <form action="aksi.php" method="POST">
        <div class="mb-3">
          <label for="inputNama" class="form-label">Nama</label>
          <div class="form-custom">
            <input class="w-100" type="text" name="nama" id="inputNama" placeholder="Muhammad Rafli" required>
          </div>
        </div>

        <div class="mb-3">
          <label for="inputDesc" class="form-label">Deskripsi Diri</label>
          <div class="form-custom text-area">
            <textarea id="inputDesc" placeholder="Deskripsikan diri anda ..." rows="3" name="desc" required></textarea>
          </div>
        </div>

        <div class="mb-3">
          <label for="" class="form-label mb-1">Tingkat Pendidikan</label>
          <div class="form-check">
            <input class="form-check-input" type="radio" name="pendidikan" id="sma" value="sma" checked>
            <label class="form-check-label" for="sma">
              SMA / Sederajat
            </label>
          </div>
          <div class="form-check">
            <input class="form-check-input" type="radio" name="pendidikan" id="s1" value="s1">
            <label class="form-check-label" for="s1">
              D4 / S1
            </label>
          </div>
          <div class="form-check">
            <input class="form-check-input" type="radio" name="pendidikan" id="s2" value="s2">
            <label class="form-check-label" for="s2">
              S2
            </label>
          </div>
        </div>
        <div class="mb-3">
          <label class="form-label mb-1">Penghasilan per Bulan</label>
          <select class="form-select" aria-label="Select Penghasilan" required>
            <option selected hidden value="">Penghasilan</option>
            <option value="1">Rp 5.000.000 - 10.000.000</option>
            <option value="2">Rp 10.000.000 - 15.000.000</option>
            <option value="3">Rp 15.000.000 - 20.000.000</option>
            <option value="4">> Rp 20.000.000</option>
          </select>
        </div>

        <!-- Checkbox -->
        <div class="mb-3">
          <div class="form-check">
            <input class="form-check-input" type="checkbox" name="t&c" value="true" id="setuju" />
            <label class="form-check-label" for="setuju">
              Saya menyetujui persyaratan dan kondisi yang ada.
            </label>
          </div>
        </div>
        <button type="submit" class="btn btn-black w-100">Kirim</button>
      </form>
    </div>
  </main>

  <footer class="px-4 py-3 fw-bold text-center"></footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
  <script>
    // Buat Tahun di footer doang
    document.querySelector('footer').innerHTML =
      '&copy; Copyright ' + new Date().getFullYear() + ' Muhammad Rafli';
  </script>
</body>

</html>