<?php

session_start();

if (isset($_SESSION["login"])) {
  header("Location: home.php");
  exit;
}

if (isset($_GET["pesan"])) {
  $status = $_GET["pesan"];
  if ($status == "input_salah") {
    $state = "danger";
    $pesan = "Username atau password yang anda masukkan salah!";
  } else if ($status == "belum_login") {
    $pesan = "Anda perlu login terlebih dahulu.";
  } else if ($status == "logout") {
    $pesan = "Anda telah berhasil melakukan logout.";
  } else if ($status == "register_success") {
    $state = "success";
    $pesan = "Anda telah berhasil melakukan registrasi, silakan login.";
  }
} else {
  $pesan = "";
}

?>

<!DOCTYPE html>
<html lang="id">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Login</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous" />
  <link rel="stylesheet" href="./assets/style.css">
</head>

<body class="">
  <div class="main-container main">
    <div class="container-custom login-container">
      <?php if ($pesan != "") : ?>
        <div class="msg-box <?= $state ?>">
          <p class="m-0"><?= $pesan ?></p>
        </div>
      <?php endif; ?>
      <h3 class="mb-2 h-custom">Login</h3>
      <form action="./utils/auth.php" method="POST">
        <div class="mb-3">
          <label for="inputUsername" class="form-label">Username</label>
          <div class="form-custom">
            <iconify-icon icon="bx:user" width="24"></iconify-icon>
            <input class="w-100" type="text" name="username" id="inputUsername" placeholder="Username" required>
          </div>
        </div>

        <div class="mb-3">
          <label for="inputPwd" class="form-label">Password</label>
          <div class="form-custom">
            <iconify-icon icon="bx:key" width="24"></iconify-icon>
            <input class="w-100" type="password" name="password" id="inputPwd" placeholder="Password" required>
          </div>
        </div>
        <button type="submit" class="btn btn-black w-100">Masuk</button>
      </form>
      <p class="mt-2 mb-0">
        Belum mempunyai akun?
        <span>
          <a class="text-dark" href="./register.php">Daftar</a>
        </span>
      </p>
    </div>
  </div>
  <footer class="px-4 py-3 text-center"></footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-OERcA2EqjJCMA+/3y+gxIOqMEjwtxJY7qPCqsdltbNJuaOe923+mo//f6V8Qbsw3" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
  <script>
    // Buat Tahun di footer doang
    document.querySelector('footer').innerHTML =
      '&copy; Copyright ' + new Date().getFullYear() + ' Muhammad Rafli';
  </script>
</body>

</html>