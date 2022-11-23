<?php

session_start();
require_once './controller/koneksi.php';
require_once './controller/query_read.php';

if (!isset($_SESSION['username'])) {
  header("Location: index.php?pesan=belum_login");
}

$fakultas = select_fakultas();

if (!isset($_GET['fak'])) {
  $query = 'SELECT * FROM data 
            INNER JOIN fakultas ON data.fakultas = fakultas.id_fakultas';
} else {
  $id_fak = $_GET['fak'];
  $query = "SELECT * FROM data 
            INNER JOIN fakultas ON data.fakultas = fakultas.id_fakultas
            WHERE id_fakultas = $id_fak";
}

$result = mysqli_query($connection, $query);

if ($result) {
  $data = [];
  while ($row = mysqli_fetch_assoc($result)) {
    $data[] = $row;
  }
} else {
  echo "Error: " . mysqli_error($connection);
}

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
            <a class="nav-link" href="tambah_mhs.php">Tambah Data</a>
          </li>
          <li class="nav-item">
            <a class="nav-link active" href="read_mhs.php">Data Mahasiswa</a>
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

  <div class="col container py-4">
    <h2 class="mb-4">Data Mahasiswa</h2>
    <table class="table table-bordered">
      <thead>
        <tr>
          <th scope="col">NIM</th>
          <th scope="col">Nama Lengkap</th>
          <th scope="col">Fakultas</th>
          <th scope="col">Angkatan</th>
          <th scope="col" colspan="2" class="text-center">Aksi</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($data as $mhs) : ?>
          <tr>
            <td><?= $mhs['nim'] ?></td>
            <td><?= $mhs['nama'] ?></td>
            <td><?= $mhs['fakultas'] ?></td>
            <td><?= $mhs['angkatan'] ?></td>
            <td class="text-center">
              <a href="edit_mhs.php?nim=<?= $mhs['nim'] ?>" class="btn btn-light">
                Edit
              </a>
            </td>
            <td class="text-center">
              <a href="./controller/query_delete.php?nim=<?= $mhs['nim'] ?>" class="btn btn-light">
                Delete
              </a>
            </td>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>