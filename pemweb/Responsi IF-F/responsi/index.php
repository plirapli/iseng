<?php

session_start();

if (isset($_SESSION["username"])) {
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
	$msg = '';
}

?>

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Bootstrap demo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
  </head>
  <body class="min-vh-100 col-md-7 container d-flex align-items-center p-4" >
  	<div class="p-4 w-100 rounded-3 text-white d-flex flex-column" style="background: url('./assets/bg.jpg'); background-size: cover;">
  		<div class="text-center">
	  		<h1>Kedai Yukihira</h1>
	    <h2>LOGIN</h2>
	    <p class="fw-bold"><?= $msg ?></p>
	  	</div>

	    <form class="col-md-6 align-self-end mt-4 d-flex flex-column align-items-center" method="POST" action="./controller/auth.php">
				<div class="mb-3 text-center">
				  <label for="inputUsername" class="text-center form-label">Username</label>
				  <input type="text" name="username" class="form-control border-white bg-transparent text-white" id="inputUsername">
				</div>
				<div class="mb-3 text-center">
				  <label for="inputPassword" class="form-label text-center">Password</label>
				  <input type="name" name="password" class="form-control bg-transparent border-white text-white" id="inputPassword">
				</div>
				<button type="submit" class="btn btn-outline-light">Login</button>
	    </form>
  	</div>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
  </body>
</html>