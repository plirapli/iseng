<?php

session_start();
require './controller/query.php';

if (!isset($_SESSION["username"])) {
  header("Location: index.php?pesan=belum_login");
  exit;
}

$movies = read_movies();

?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Login</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body class="container min-vh-100 d-flex justify-content-center align-items-center p-4">
  <div class="row">
    <div style="color: #64aeeb;" class="p-4 col-md-8 d-flex flex-column justify-content-center text-center">
      <h1 class="display-3 fw-semibold">Movie List</h1>
      <div>
        <a href="add_movie.php" class="btn btn-outline-primary">Add Movie List</a>
        <a href="./controller/logout.php" class="btn btn-outline-warning">Logout</a>
      </div>
      <table style="border-color: #64aeeb; color: #64aeeb;" class="mt-5 table table-bordered">
        <thead>
          <tr>
            <th scope="col">No.</th>
            <th scope="col">Title</th>
            <th scope="col">Genre</th>
            <th scope="col" colspan="2">Action</th>
          </tr>
        </thead>
        <tbody>
          <?php $no = 1; ?>
          <?php foreach ($movies as $movie) : ?>
            <tr>
              <th scope="row"><?= $no++ ?></th>
              <td><?= $movie["title"] ?></td>
              <td><?= $movie["genre"] ?></td>
              <td>
                <a href="edit_movie.php?id=<?= $movie["id_movie"] ?>" class="btn btn-outline-primary">Edit</a>
              </td>
              <td>
                <a href="./controller/query_delete.php?id=<?= $movie["id_movie"] ?>" class="btn btn-outline-warning">Delete</a>
              </td>
            </tr>
          <?php endforeach; ?>
        </tbody>
      </table>
    </div>
    <img src="./assets/minion.jpg" alt="" class="col-md-4">
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>