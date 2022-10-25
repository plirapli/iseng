<?php

$serverdb = "localhost";
$username = "admin";
$password = "Admin123*";
$db = "toko2";

$mydb = new mysqli($serverdb,$username,$password, $db);

$sql = "select * from products";

$produk = $mydb->query($sql);

while($row = $produk->fetch_object()) {
    print $row->productCode." | ". $row->productName. " | ". $row->buyPrice;
    print "<br>";
}

