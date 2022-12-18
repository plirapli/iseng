<?php

require 'konek.php';

function get_menu() {
	global $connection;

	$query = 'SELECT * FROM menu';
	$result = mysqli_query($connection, $query);

	if ($result) {
		$rows = [];
		while ($row = mysqli_fetch_assoc($result)) {
			$rows[] = $row;
		}

		return $rows;
	} else {
		echo "Error: " . mysqli_error($connection);
		return;
	}
}

function get_menu_id($id) {
	global $connection;

	$query = "SELECT * FROM menu WHERE id_menu = $id";
	$result = mysqli_query($connection, $query);

	if ($result) {
		$rows = [];
		while ($row = mysqli_fetch_assoc($result)) {
			$rows[] = $row;
		}

		return $rows[0];
	} else {
		echo "Error: " . mysqli_error($connection);
		return;
	}
}