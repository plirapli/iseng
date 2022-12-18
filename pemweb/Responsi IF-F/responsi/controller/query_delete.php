<?php

require 'konek.php';

$id = $_GET["id"];

$query = "DELETE FROM menu WHERE id_menu = $id";
$result = mysqli_query($connection, $query);

if ($result) {
	header("Location: ../home.php");
} else {
	echo "Error: " . mysqli_error($connection);
}
