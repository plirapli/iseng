<?php

require 'konek.php';

$id = $_GET["id"];
$menu = $_POST["menu"];
$category = $_POST["category"];
$price = $_POST["price"];

$query = "UPDATE menu 
		  SET menu = '$menu', category = '$category', price = $price
		  WHERE id_menu = $id";
$result = mysqli_query($connection, $query);

if ($result) {
	header("Location: ../home.php");
} else {
	echo "Error: " . mysqli_error($connection);
}
