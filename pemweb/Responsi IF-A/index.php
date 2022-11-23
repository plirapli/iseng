<?php

session_start();
if (isset($_SESSION['username'])) {
  header("Location: home.php");
}

if (isset($_GET['pesan'])) {
  $pesan = $_GET['pesan'];
  if ($pesan == 'login_gagal') {
    $msg = 'Username atau Password salah!';
  } else if ($pesan == 'belum_login') {
    $msg = 'Anda perlu login terlebih dahulu.';
  } else if ($pesan == 'logout') {
    $msg = 'Anda telah berhasil logout.';
  }
} else {
  $msg = 'Please enter your login & password!';
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Login</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body class="min-vh-100 container d-flex align-items-center">
  <div class="d-flex w-100 justify-content-center">
    <div style="padding-bottom: 10rem!important;" class="col-xl-4 p-5 bg-dark text-white text-center rounded-4">
      <h2>LOGIN</h2>
      <p class="text-white-50"><?= $msg ?></p>

      <form action="./controller/auth.php" method="POST" class="mt-5">
        <div class="mb-4">
          <input type="email" name="username" class="form-control" placeholder="Email">
        </div>
        <div class="mb-5">
          <input type="password" name="password" class="form-control" placeholder="Password">
        </div>
        <button type="submit" class="btn btn-outline-light px-5">Login</button>
      </form>
    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>