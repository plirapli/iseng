<?php
$mahasiswa = [
  ["nama" => "Rafli", "nim" => "123210078",],
  ["nama" => "Seva", "nim" => "123210061",],
  ["nama" => "Syaikul", "nim" => "123210081",],
];

?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>

<body>
  <h1>Daftar Mahasiswa</h1>
  <ul>
    <?php foreach ($mahasiswa as $mhs) : ?>
      <li>
        <!-- Klik salah satu mahasiswa untuk melihat detail -->
        <a href="getDetail.php?nama=<?= $mhs["nama"]; ?>&nim=<?= $mhs["nim"]; ?>">
          <?= $mhs["nama"] ?>
        </a>
      </li>
    <?php endforeach; ?>
  </ul>
</body>

</html>