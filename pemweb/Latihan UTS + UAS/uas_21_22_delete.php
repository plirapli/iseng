<?php

$connect = new mysqli('localhost', 'root', '', 'nwind');
$id = $_GET['id'];
$sql = "DELETE FROM products WHERE ProductID = $id";
$result = $connect->query($sql);

if ($result) {
  header("Location: uas.php");
} else {
  echo "Error: " . $connect->error;
}
