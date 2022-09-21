<?php

// Buat nyimpen lembar pecahan
$lembar = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
$pecahan = [100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100];

// Hasil input user
$harga = $_GET["harga"];
$uang = $_GET["uang"];


function kembalian($harga, $uang)
{
  global $pecahan, $lembar;

  $kembalian = $uang - $harga;

  if ($kembalian >= 0) {
    for ($i = 0; $i < count($pecahan); $i++) {
      if ($kembalian - $pecahan[$i] >= 0) {
        $kembalian -= $pecahan[$i];
        $lembar[$i]++;
        $i--;
      }
    }
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
</head>

<body>
  <table>
    <tr>
      <th>Uang</th>
      <td>Rp <?= $uang; ?></td>
    </tr>
    <tr>
      <th>Harga</th>
      <td>Rp <?= $harga ?></td>
    </tr>
    <tr>
      <th>Kembalian</th>
      <td>Rp <?= $uang - $harga; ?></td>
    </tr>
  </table>
  <br>
  <table>
    <tr>
      <th>Pecahan (Rp)</th>
      <th>Lembar</th>
    </tr>
    <?php foreach ($total[0] as $lembaran => $value) : ?>
      <tr>
        <td><?= $total[1][$lembaran] ?></td>
        <td><?= $total[0][$lembaran] ?></td>
      </tr>
    <?php endforeach; ?>
  </table>
</body>

</html>