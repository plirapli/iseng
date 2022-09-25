<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Login</title>
  <link rel="shortcut icon" href="./assets/favicon/round-login.svg" type="image/x-icon">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous" />
  <link rel="stylesheet" href="./assets/style.css" />
</head>

<body>
  <div class="main-container main">
    <div class="container-custom">
      <h3 class="mb-3 h-custom">Login</h3>
      <form action="./pages/home.php" method="POST">
        <div class="mb-3">
          <label for="inputNama" class="form-label">Nama</label>
          <div class="form-custom">
            <iconify-icon icon="bi:person" width="24"></iconify-icon>
            <input type="text" name="nama" id="inputNama" placeholder="Muhammad Rafli" required>
          </div>
        </div>

        <div class="mb-3">
          <label for="inputNim" class="form-label">NIM</label>
          <div class="form-custom">
            <iconify-icon icon="fluent:document-page-number-24-regular" width="24"></iconify-icon>
            <input type="text" name="nim" id="inputNim" placeholder="123210***" required aria-describedby="nimHelp">
          </div>
          <div id="nimHelp" class="form-text">NIM terdiri dari 9 karakter</div>
        </div>
        <button type="submit" class="btn btn-black w-100">Masuk</button>
      </form>
    </div>
  </div>
  <footer class="px-4 py-3 fw-bold text-center"></footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
  <script src="https://code.iconify.design/iconify-icon/1.0.0/iconify-icon.min.js"></script>
  <script>
    // Buat Tahun di footer doang
    document.querySelector('footer').innerHTML =
      '&copy; Copyright ' + new Date().getFullYear() + ' Muhammad Rafli';
  </script>
</body>

</html>