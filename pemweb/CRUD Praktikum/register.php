<?php

session_start();

if (isset($_SESSION["login"])) {
  header("Location: home.php");
  exit;
}

if (isset($_GET["pesan"])) {
  $status = $_GET["pesan"];
  if ($status == "password_beda") {
    $state = "danger";
    $pesan = "Konfirmasi password tidak cocok!";
  } else if ($status == "username_ada") {
    $state = "danger";
    $pesan = "Username telah terdaftar!";
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
  <title>Register</title>
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
      <h3 class="mb-2 h-custom">Register</h3>
      <form action="./utils/auth_register.php" method="POST">
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
        <div class="mb-3">
          <label for="inputPwd" class="form-label">Confirm Password</label>
          <div class="form-custom">
            <iconify-icon icon="bx:key" width="24"></iconify-icon>
            <input class="w-100" type="password" name="confirm_password" id="inputPwd" placeholder="Confirm Password" required>
          </div>
        </div>
        <button type="submit" class="btn btn-black w-100">Daftar</button>
      </form>
      <p class="mt-2 mb-0">
        Sudah mempunyai akun?
        <span>
          <a class="text-dark" href="./index.php">Masuk</a>
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