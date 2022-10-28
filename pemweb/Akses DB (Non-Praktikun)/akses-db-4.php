<!doctype html>
<html lang="en">

<?php
$serverdb = "localhost";
$username = "rafli";
$password = "123";
$db = "test";
$mydb = new mysqli($serverdb, $username, $password, $db);
$query = "SELECT * FROM products";
$result = $mydb->query($query);

while ($row = $result->fetch_assoc()) {
	echo "Product: " . $row["productCode"] . "<br>";
}
?>

</html>