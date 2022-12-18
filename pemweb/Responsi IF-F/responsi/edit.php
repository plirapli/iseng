<?php

session_start();
require './controller/query_read.php';

if (!isset($_SESSION["username"])) {
	header("Location: index.php?pesan=belum_login");
}

$menu = get_menu_id($_GET["id"]);

?>

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Bootstrap demo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">

    <style type="text/css">
    	.btn-abu {
    		color: white;
    		background-color: #465771 !important;
    	}

    </style>
  </head>
  <body class="min-vh-100 d-flex justify-content-center align-items-center p-4" >
  	<div class="col-md-4">
  		<div class="d-flex flex-column align-items-center">
	  		<h1 style="color: #465771;">Update Menu</h1>
		    <div>
		    	<a href="home.php" class="btn btn-abu">Home</a>
		    	<a href="./controller/logout.php" class="btn btn-danger">Logout</a>
		    </div>
	  	</div>
	  	<form class="mt-4 d-flex flex-column" method="POST" action="./controller/query_edit.php?id=<?= $_GET["id"] ?>">
				<div class="row mb-3">
			    <label for="inputMenu" class="fw-bold col-sm-3 col-form-label">Menu</label>
			    <div class="col-sm-9">
			      <input type="text" value="<?= $menu["menu"] ?>" name="menu" class="form-control" id="inputMenu">
			    </div>
			  </div>
			  <div class="row mb-3 align-items-center">
			    <label for="inputMenu" class="fw-bold col-sm-3 col-form-label">Category</label>
			    <div class="col-sm-9">
			    	<div class="form-check form-check-inline">
						  <input class="form-check-input" type="radio" name="category" id="food" value="food" <?= $menu["category"] == "food" ? "checked" : "" ?>>
						  <label class="form-check-label" for="food">Food</label>
			    	</div>
			    	<div class="form-check form-check-inline">
						  <input class="form-check-input" type="radio" name="category" id="drink" value="drink" <?= $menu["category"] == "drink" ? "checked" : "" ?>>
						  <label class="form-check-label" for="drink">Drink</label>
			    	</div>
			    </div>
			  </div>
			  <div class="row mb-3">
			    <label for="inputMenu" class="fw-bold col-sm-3 col-form-label">Price</label>
			    <div class="col-sm-9">
			      <input type="number" value="<?= $menu["price"] ?>" name="price" class="form-control" id="inputMenu">
			    </div>
			  </div>
				<button type="submit" class="btn btn-primary btn-abu align-self-center">	Update Menu
				</button>
	    </form>
  	</div>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
  </body>
</html>