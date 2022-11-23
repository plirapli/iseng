<?php

session_start();
require './controller/query.php';

if (!isset($_SESSION["username"])) {
  header("Location: index.php?pesan=belum_login");
  exit;
}

if (!isset($_GET["id"])) {
  header("Location: home.php");
  exit;
}

$genres = read_genres();
$movie = read_movies_id($_GET["id"]);

?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Login</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
  <link rel="stylesheet" href="./assets/style.css">
</head>

<body class="container min-vh-100 d-flex justify-content-center align-items-center">
  <div style="color: #64aeeb;" class="p-5 col-8 d-flex flex-column justify-content-center text-center">
    <h1 class="display-3 fw-semibold">Update Movie List</h1>
    <div class="mb-5">
      <a href="home.php" class="btn btn-outline-primary">Home</a>
      <a href="logout.php" class="ms-3 btn btn-outline-warning">Logout</a>
    </div>
    <form method="POST" action="./controller/query_edit.php?id=<?= $movie["id_movie"] ?>">
      <div class="mb-3 d-flex align-items-center gap-2">
        <label for="inputTitle" class="fw-bold form-label col-sm-4">Title</label>
        <input type="text" name="title" value="<?= $movie["title"] ?>" class="form-control border border-info text-primary" id="inputTitle">
      </div>
      <div class="mb-5 d-flex align-items-center gap-2">
        <label for="selectGenre" class="fw-bold form-label col-sm-4">Genre</label>
        <select name="genre" class="form-select border border-info text-primary" aria-label="Default select example">
          <?php foreach ($genres as $genre) : ?>
            <option value="<?= $genre["id_genre"] ?>" <?= $genre["id_genre"] == $movie["id_genre"] ? 'selected' : '' ?>>
              <?= $genre["genre"] ?>
            </option>
          <?php endforeach; ?>
        </select>
      </div>
      <button type="submit" name="add_movies" class="btn btn-biru text-white">Update Movie</button>
    </form>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>