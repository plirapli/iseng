<?php
echo "<b>UAS 2021/2021</b> <br>" .
  "<a href='uas_22_23_no_1.php'>UAS 2022/2023</a> <br>" .
  "<a href='uts_21_22.php'>UTS 2021/2022</a>";
echo "<h2>UAS 2021/2022</h2>";

$connect = new mysqli('localhost', 'root', '', 'nwind');

// NO. 1
echo "1. Tuliskanlah kode program PHP sesingkat mungkin untuk membuat web yang akan menampilkan daftar nama products dan nama suppliers nya dari database NWIND ! <br><br>" .
  "Jawab: <br>";

$sql_1 = 'SELECT p.ProductID AS id, p.ProductName AS product, s.CompanyName AS supplier FROM products p 
          INNER JOIN suppliers s ON p.SupplierID = s.SupplierID';
$result_1 = $connect->query($sql_1);
while ($row = $result_1->fetch_object()) {
  echo "Product: $row->product <br>";
  echo "Supplier: $row->supplier <br>";
  echo "<a href='uas_delete.php?id=$row->id'>Hapus</a> <br><br>";
}
echo "<br>";

// NO. 2
echo "2. Tuliskanlah kode program PHP sesingkat mungkin untuk membuat web yang akan menampilkan daftar pelanggan dari database NWIND yang ContactName-nya diawali dengan huruf “R”! <br><br>" .
  "Jawab: <br>";

$sql_2 = "SELECT * FROM customers WHERE ContactName LIKE 'R%'";
$result_2 = $connect->query($sql_2);
while ($row = $result_2->fetch_object()) {
  echo "ID: $row->CustomerID <br>";
  echo "Company Name: $row->CompanyName <br>";
  echo "Contact Name: $row->ContactName <br>";
  echo "Contact Title: $row->ContactTitle <br>";
  echo "Address: $row->Address <br>";
  echo "City: $row->City <br>";
  echo "Region: $row->Region <br>";
  echo "Postal Code: $row->PostalCode <br>";
  echo "Country: $row->Country <br>";
  echo "Phone: $row->Phone <br>";
  echo "Fax: $row->Fax <br><br>";
}
