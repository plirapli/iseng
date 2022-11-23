<?php

session_start();
if (isset($_SESSION["username"])) {
  header("Location: home.php");
  exit;
}

if (isset($_GET["pesan"])) {
  $pesan = $_GET["pesan"];
  if ($pesan == 'login_gagal') {
    $msg = 'Username atau password salah!';
  } else if ($pesan == 'belum_login') {
    $msg = 'Silakan login terlebih dahulu.';
  } else if ($pesan == 'logout') {
    $msg = 'Anda telah berhasil logout.';
  }
} else {
  $msg = '';
}

?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Login</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body class="container min-vh-100 d-flex justify-content-center align-items-center">
  <div class="row">
    <img src="./assets/popcorn.jpg" alt="" style="object-fit: cover;" class="col-sm-3">
    <div class="p-5 col-sm-9 text-warning d-flex flex-column justify-content-center text-center">
      <h1 class="display-3 fw-semibold">LOGIN</h1>
      <div><?= $msg ?></div>
      <form class="mt-5" action="./controller/auth.php" method="POST">
        <div class="mb-3 d-flex align-items-center gap-2">
          <label for="inputUsername" class="form-label col-sm-3">Username</label>
          <input type="text" name="username" class="form-control border border-warning" id="inputUsername">
        </div>
        <div class="mb-5 d-flex align-items-center gap-2">
          <label for="inputPassword" class="form-label col-sm-3">Password</label>
          <input type="password" name="password" class="form-control border border-warning" id="inputPassword">
        </div>
        <button type="submit" class="btn btn-warning text-white">Login</button>
      </form>
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>