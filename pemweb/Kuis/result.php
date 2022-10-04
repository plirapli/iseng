<?php
$total = $_POST["price"] - $_POST["disc"];

$orders = [
  'Menu' => $_POST["menu"],
  'Category' => $_POST["cat"],
  'Price' => $_POST["price"],
  'Discount' => $_POST["disc"],
  'Total' => $total,
  'Order' => $_POST["orderType"],
  'Note' => $_POST["note"],
];
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Result</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
</head>

<body style="min-height: 100vh;" class="bg-dark p-5 d-flex flex-column justify-content-center align-items-center gap-5">
  <h1 class="text-white">Here's your Order</h1>
  <table style="width: fit-content;" class="table table-dark table-striped-columns">
    <?php foreach ($orders as $key => $order) : ?>
      <tr>
        <td><?= $key ?></td>
        <td><?= $order; ?></td>
      </tr>
    <?php endforeach ?>
  </table>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-OERcA2EqjJCMA+/3y+gxIOqMEjwtxJY7qPCqsdltbNJuaOe923+mo//f6V8Qbsw3" crossorigin="anonymous"></script>
</body>

</html>