<!doctype html>
<html lang="en">

<?php
$serverdb = "localhost";
$username = "rafli";
$password = "123";
$db = "test";
$mydb = new mysqli($serverdb, $username, $password, $db);
?>

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css" integrity="sha384-B0vP5xmATw1+K9KRQjQERJvTumQW0nPEzvF6L/Z6nronJ3oUOFUFpCjEUQouq2+l" crossorigin="anonymous">
</head>

<body>
	<div class="mt-4 container-fluid">
		<div class="row">
			<div class="col-sm-3">
				<div class="list-group">
					<?php
					$sql = "select * from productlines";
					$result = $mydb->query($sql);

					while ($row = $result->fetch_assoc()) : ?>
						<a href="akses-db-3.php?pline=<?= $row['productLine'] ?>" class="list-group-item list-group-item-action"><?= $row['productLine'] ?></a>
					<?php endwhile ?>
				</div>
			</div>
			<div class="col-sm-9">
				<?php
				if (isset($_GET['pline'])) {
					$pl = $_GET['pline'];
					$sql = "select * from products where productLine = '$pl'";
				} else {
					$sql = "select * from products";
				}
				$produk = $mydb->query($sql);
				?>
				<h1>Product List</h1>
				<table class="table table-striped">
					<?php

					while ($row = $produk->fetch_assoc()) {

					?>
						<tr>
							<td><?= $row['productCode'] ?></td>
							<td><?= $row['productName'] ?></td>
							<td><?= $row['buyPrice'] ?></td>
						</tr>
					<?php
					}
					?>
				</table>
			</div>
		</div>
	</div>

	<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-Piv4xVNRyMGpqkS2by6br4gNJ7DXjqk09RmUpJ8jgGtD7zP9yug3goQfGII0yAns" crossorigin="anonymous"></script>
</body>

</html>