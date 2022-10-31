<?php

require '../utils/query_jadwal.php';
require '../utils/query_lab.php';
require '../utils/query_waktu.php';

// Buat Read Table
$daftar_jadwal = select_all_jadwal();
$daftar_lab = select_all_lab();
$daftar_waktu = select_all_waktu();

// Buat Create Data
// Cek tombol submit pada form daftar dah ditekan/belum
if (isset($_POST["submit"])) {
  if (add_jadwal($_POST) > 0) {
    header("Location: jadwal.php");
  } else {
    echo "Failed";
  }
}

// if(isset($))

// Buat Edit Data
// Cek apakah tombol "edit" dah diklik/belum
if (isset($_POST["submit_edit"])) {
  if (edit_jadwal($_POST) > 0) {
    header("Location: jadwal.php");
  } else {
    echo "Failed";
  }
}

// Buat Hapus Data
// Cek apakah tombol "hapus" dah diklik/belum
if (isset($_GET["id"])) {
  if (delete_jadwal($_GET["id"]) > 0) {
    header("Location: jadwal.php");
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
          <a class="nav-link nav-text nav-custom" href="waktu.php">
            <iconify-icon icon="bx:time-five" width="18"></iconify-icon>
            Waktu
          </a>
          <a class="nav-link active nav-text nav-custom" href="jadwal.php">
            <iconify-icon icon="bx:calendar" width="18"></iconify-icon>
            Jadwal
          </a>
        </div>
      </div>
    </div>
  </nav>
  <!-- NAVBAR END -->

  <main class="mt-2 container">
    <div class="row gap-2">
      <section class="col-xl">
        <h2>Jadwal</h2>
        <table class="table">
          <thead>
            <tr>
              <th class="text-center" scope="col">No.</th>
              <th class="text-center" scope="col">Mata Kuliah</th>
              <th class="text-center" scope="col">Prodi</th>
              <th class="text-center" scope="col">Lab</th>
              <th class="text-center" scope="col">Waktu</th>
              <th class="text-center" scope="col">Aksi</th>
            </tr>
          </thead>
          <tbody>
            <?php $no = 1; ?>
            <?php foreach ($daftar_jadwal as $jadwal) : ?>
              <tr>
                <th class=" text-center" scope="row"><?= $no++; ?>.</th>
                <td class="text-center"><?= $jadwal["mata_kuliah"]; ?></td>
                <td class="text-center"><?= $jadwal["program_studi"]; ?></td>
                <td class="text-center"><?= $jadwal["nama_lab"]; ?></td>
                <td class="text-center">
                  <?= $jadwal["waktu_mulai"]; ?>
                  -
                  <?= $jadwal["waktu_selesai"]; ?>
                </td>
                <td class="text-center">
                  <button data-bs-toggle="modal" data-bs-target="#modal_<?= $jadwal["id"]; ?>" class="btn btn-dark pb-0 px-2">
                    <iconify-icon icon="bx:pencil" width="24"></iconify-icon>
                  </button>
                  <a class="btn btn-danger pb-0 px-2" href="jadwal.php?id=<?= $jadwal["id"] ?>">
                    <iconify-icon icon="bx:trash" width="24"></iconify-icon>
                  </a>
                </td>
              </tr>
            <?php endforeach; ?>
          </tbody>
        </table>
      </section>
      <section class="col-xl container-custom">
        <h3 class="mb-3 h-custom">Waktu Praktikum</h3>
        <form method="POST">
          <div class="row">
            <div class="mb-3">
              <label for="inputMk" class="form-label">Mata Kuliah</label>
              <div class="d-flex">
                <div class="form-custom me-4 w-100">
                  <iconify-icon icon="akar-icons:book" width="20"></iconify-icon>
                  <input class="w-100" type="text" name="matkul" id="inputMk" placeholder="Masukkan mata kuliah" required>
                </div>
                <div class="mt-1 form-check form-check-inline">
                  <input class="form-check-input" type="radio" name="prodi" value="IF" id="radio-if" checked>
                  <label class="form-check-label" for="radio-if">
                    IF
                  </label>
                </div>
                <div class="mt-1 form-check form-check-inline">
                  <input class="form-check-input" type="radio" name="prodi" value="SI" id="radio-si">
                  <label class="form-check-label" for="radio-si">
                    SI
                  </label>
                </div>
              </div>
            </div>
            <div class="mb-3">
              <label class="form-label mb-1">Lab Praktikum</label>
              <select class="form-select" name="lab" aria-label="Select Lab" required>
                <option selected hidden value="">Pilih Lab</option>
                <?php foreach ($daftar_lab as $lab) : ?>
                  <option value='<?= $lab["id"] ?>'>
                    <?= $lab["nama"] ?>
                  </option>
                <?php endforeach; ?>
              </select>
            </div>
            <div class="mb-3">
              <label class="form-label mb-1">Waktu Praktikum</label>
              <select class="form-select" name="waktu" aria-label="Select Waktu" required>
                <option selected hidden value="">Pilih Waktu</option>
                <?php foreach ($daftar_waktu as $waktu) : ?>
                  <option value='<?= $waktu["id"] ?>'>
                    <?= $waktu["mulai"] ?> - <?= $waktu["selesai"] ?>
                  </option>
                <?php endforeach; ?>
              </select>
            </div>
          </div>
          <div class="row w-100 m-0 gap-2 mt-3">
            <button type="reset" name="reset" class="col-sm btn btn-outline-dark w-100">Reset</button>
            <button type="submit" name="submit" class="col-sm btn btn-black w-100">Daftar</button>
          </div>
        </form>
      </section>
    </div>
  </main>
  <footer class="px-4 py-3 fw text-center"></footer>

  <!-- Modal -->
  <?php foreach ($daftar_jadwal as $jadwal) : ?>
    <div class="modal fade" id="modal_<?= $jadwal["id"] ?>" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <h1 class="modal-title fs-5" id="exampleModalLabel">Edit Jadwal</h1>
            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
          </div>
          <form method="POST">
            <div class="modal-body">
              <div class="row">
                <input type="hidden" name="id" value="<?= $jadwal["id"] ?>">
                <div class="mb-3">
                  <label for="inputMk" class="form-label">Mata Kuliah</label>
                  <div class="d-flex">
                    <div class="form-custom me-4 w-100">
                      <iconify-icon icon="akar-icons:book" width="20"></iconify-icon>
                      <input class="w-100" type="text" value="<?= $jadwal["mata_kuliah"] ?>" name="matkul" id="inputMk" placeholder="Masukkan mata kuliah" required>
                    </div>
                    <div class="mt-1 form-check form-check-inline">
                      <input class="form-check-input" type="radio" name="prodi" value="IF" id="radio-if" <?= $jadwal["program_studi"] == "IF" ? "checked" : "" ?>>
                      <label class="form-check-label" for="radio-if">
                        IF
                      </label>
                    </div>
                    <div class="mt-1 form-check form-check-inline">
                      <input class="form-check-input" type="radio" name="prodi" value="SI" id="radio-si" <?= $jadwal["program_studi"] == "SI" ? "checked" : "" ?>>
                      <label class="form-check-label" for="radio-si">
                        SI
                      </label>
                    </div>
                  </div>
                </div>
                <div class="mb-3">
                  <label class="form-label mb-1">Lab Praktikum</label>
                  <select class="form-select" name="lab" aria-label="Select Lab" required>
                    <?php foreach ($daftar_lab as $lab) : ?>
                      <option value='<?= $lab["id"] ?>' <?= $jadwal["id_lab"] == $lab["id"] ? "selected" : "" ?>>
                        <?= $lab["nama"] ?>
                      </option>
                    <?php endforeach; ?>
                  </select>
                </div>
                <div class="mb-3">
                  <label class="form-label mb-1">Waktu Praktikum</label>
                  <select class="form-select" name="waktu" aria-label="Select Waktu" required>
                    <option selected hidden value="">Pilih Waktu</option>
                    <?php foreach ($daftar_waktu as $waktu) : ?>
                      <option value='<?= $waktu["id"] ?>' <?= $jadwal["id_waktu"] == $waktu["id"] ? "selected" : "" ?>>
                        <?= $waktu["mulai"] ?> - <?= $waktu["selesai"] ?>
                      </option>
                    <?php endforeach; ?>
                  </select>
                </div>
              </div>
            </div>
            <div class="modal-footer">
              <button type="button" class="btn btn-outline-dark" data-bs-dismiss="modal">Close</button>
              <button type="submit" name="submit_edit" class="btn btn-black">Simpan</button>
            </div>
          </form>
        </div>
      </div>
    </div>
  <?php endforeach; ?>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
  <script>
    // Buat Tahun di footer doang
    document.querySelector('footer').innerHTML =
      '&copy; Copyright ' + new Date().getFullYear() + ' Muhammad Rafli';
  </script>
</body>

</html>