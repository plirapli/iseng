<?php
$orders = [
  'product' => $_POST['product'],
  'category' => $_POST['category'],
  'price' => 'Rp ' . $_POST['price'],
  'qty' => $_POST['qty'],
  'total' => 'Rp ' . $_POST['price'] * $_POST['qty'],
  'payment' => $_POST['payment'],
  'note' => $_POST['note'],
];
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
</head>

<body style="min-height: 100vh; background: #F9A826;" class="p-4 d-flex flex-column justify-content-center align-items-center text-white">
  <h1>Thank You</h1>
  <p>for Shopping with Us</p>

  <div class="mt-4">
    <table style="width: fit-content;" class="table table-striped-columns text-white">
      <?php foreach ($orders as $key => $order) : ?>
        <tr>
          <td class="text-capitalize fw-bold"><?= $key ?></td>
          <td class="text-white"><?= $order ?></td>
        </tr>
      <?php endforeach ?>
    </table>
  </div>

  <a href="./index.php" class="mt-4">
    <button type="button" class="btn btn-outline-light">
      Buy another Products
    </button>
  </a>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-OERcA2EqjJCMA+/3y+gxIOqMEjwtxJY7qPCqsdltbNJuaOe923+mo//f6V8Qbsw3" crossorigin="anonymous"></script>
</body>

</html>