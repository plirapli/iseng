<?php

$prev_file_name = "post.php";

// Cek apakah data dah ada/belum
if (!isset($_GET["nama"])) {
  header("Location: " . $prev_file_name);
  exit;
} else {
  $mhs = $_GET;
}

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
  <h1>Detail Mahasiswa</h1>
  <ul>
    <li><?= $mhs["nama"] ?> </li>
    <li><?= $mhs["nim"] ?> </li>
  </ul>

  <a href="<?= $prev_file_name; ?>">Kembali</a>
</body>

</html>