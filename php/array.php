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

  <style>
    td {
      margin: 0;
      padding: 0.5rem;
      border: 2px solid black;
    }

    td.color {
      background: gainsboro;
    }
  </style>
</head>

<body>
  <table>
    <?php foreach ($mahasiswa as $mhs) : ?>
      <tr>
        <td><?= $mhs["nama"]; ?></td>
        <td><?= $mhs["nim"]; ?></td>
      </tr>
    <?php endforeach; ?>
  </table>

  <script>
    const tds = document.querySelectorAll("td");
    tds.forEach(td => {
      const row = parseInt(td.innerText.split('')[0])
      const col = parseInt(td.innerText.split('')[3]);
      let color;

      if (row % 2 == 0) {
        td.classList.add((col % 2 == 0) ? "color" : "white");
      } else {
        td.classList.add((col % 2 != 0) ? "color" : "white");
      }
    })
  </script>
</body>

</html>