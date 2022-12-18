<?php

require 'konek.php';

$menu = $_POST["menu"];
$category = $_POST["category"];
$price = $_POST["price"];

$query = "INSERT INTO menu 
		  VALUES ( '', '$menu', '$category', $price ) ";
$result = mysqli_query($connection, $query);

if ($result) {
	header("Location: ../home.php");
} else {
	echo "Error: " . mysqli_error($connection);
}
