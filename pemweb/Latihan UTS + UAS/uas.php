<?php

$connect = new mysqli('localhost', 'root', '', 'nwind');
$sql_1 = 'SELECT p.ProductName AS product, s.CompanyName AS supplier FROM products p 
        INNER JOIN suppliers s ON p.SupplierID = s.SupplierID';
$query_1 = $connect->query($sql_1);

echo "Nomer 1: <br>";
while ($row = $query_1->fetch_assoc()) {
  echo "Product: " . $row['product'] . "<br>";
  echo "Supplier: " . $row['supplier'] . "<br><br>";
}
echo "<br><br>";

$sql_2 = "SELECT * FROM customers WHERE ContactName LIKE 'L%'";
$query_2 = $connect->query($sql_2);

echo "Nomer 2: <br>";
while ($row = $query_2->fetch_assoc()) {
  echo "ID: " . $row['CustomerID'] . "<br>";
  echo "Company Name: " . $row['CompanyName'] . "<br>";
  echo "Contact Name: " . $row['ContactName'] . "<br>";
  echo "Contact Title: " . $row['ContactTitle'] . "<br>";
  echo "Address: " . $row['Address'] . "<br>";
  echo "City: " . $row['City'] . "<br>";
  echo "Region: " . $row['Region'] . "<br>";
  echo "Postal Code: " . $row['PostalCode'] . "<br>";
  echo "Country: " . $row['Country'] . "<br>";
  echo "Phone: " . $row['Phone'] . "<br>";
  echo "Fax: " . $row['Fax'] . "<br><br>";
}
