<?php
echo "<b>UTS 2022/2023</b> <br>" .
  "<a href='uas_22_23_no_1.php'>UAS 2022/2023</a> <br>" .
  "<a href='uas_21_22.php'>UAS 2021/2022</a>";
echo "<h2>UTS 2021/2022</h2>";

$connect = new mysqli('localhost', 'root', '', 'nwind');

$sql_1 = 'SELECT * FROM customers';
$query_1 = $connect->query($sql_1);

echo "1. Tuliskanlah kode program PHP sesingkat mungkin untuk membuat web yang akan menampilkan daftar pelanggan dari database NWIND ! <br><br>";
echo "Jawab: <br>";
while ($row = $query_1->fetch_assoc()) {
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
echo "<br>";

$sql_2 = "SELECT * FROM customers WHERE ContactName LIKE 'F%'";
$query_2 = $connect->query($sql_2);

echo "2. Tuliskanlah kode program PHP sesingkat mungkin untuk membuat web yang akan menampilkan daftar pelanggan dari database NWIND yang ContactName-nya diawali dengan huruf “F”! <br><br>";
echo "Jawab: <br>";
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
