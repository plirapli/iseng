<?php

session_start();
require './controller/query_read.php';

if (!isset($_SESSION["username"])) {
	header("Location: index.php?pesan=belum_login");
}

$data = get_menu();

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
  <body class="min-vh-100 d-flex align-items-center p-4" >
  	<div class="container d-flex">
  		<div class="col-md-9 me-4 d-flex flex-column align-items-center">
	  		<h1 style="color: #465771;">Menu</h1>
		    <div>
		    	<a href="add.php" class="btn btn-abu">Add Menu</a>
		    	<a href="./controller/logout.php" class="btn btn-danger">Logout</a>
		    </div>

		    <table class="mt-5 table table-bordered border-danger">
				  <thead>
				    <tr>
				      <th scope="col">No</th>
				      <th scope="col">Menu</th>
				      <th scope="col">Category</th>
				      <th scope="col">Price</th>
				      <th scope="col" colspan="2" class="text-center">Action</th>
				    </tr>
				  </thead>
				  <tbody>
				  	<?php $i = 1; $total = 0; ?>
				  	<?php foreach ($data as $menu) : ?>
					    <tr>
					      <th scope="row"><?= $i++ ?></th>
					      <td><?= $menu["menu"] ?></td>
					      <td class="text-capitalize"><?= $menu["category"] ?></td>
					      <td><?= $menu["price"] ?></td>
					      <td class="text-center">
					      	<a href="edit.php?id=<?= $menu["id_menu"] ?>" class="btn btn-outline-secondary">Edit</a>
					      </td>
					      <td class="text-center">
					      	<a href="./controller/query_delete.php?id=<?= $menu["id_menu"] ?>" class="btn btn-outline-danger">Delete</a>
					      </td>
					    </tr>

					    <?php $total += $menu["price"] ?>
				  	<?php endforeach ?>
				  </tbody>
				  <thead>
				    <tr>
				      <th scope="col" class="text-center" colspan="3">Total</th>
				      <th scope="col" class="text-center" colspan="3">
				      	<?= $total; ?>
				      </th>
				    </tr>
				  </thead>
				</table>
	  	</div>
	    <img class="col-md-3" src="./assets/souma.jpg">
  	</div>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
  </body>
</html>