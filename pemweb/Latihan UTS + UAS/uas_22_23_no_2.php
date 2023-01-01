<?php
echo "<b>UAS 2022/2023</b> <br>" .
  "<a href='uas_21_22.php'>UAS 2021/2022</a> <br>" .
  "<a href='uts_22_23.php'>UTS 2022/2023</a>";
echo "<h2>UAS 2022/2023</h2>";

$connect = new mysqli('localhost', 'root', '', 'nwind');

// NO. 1
$id = $_GET['id'];
$sql = "SELECT ProductID, ProductName, UnitPrice, CompanyName 
        FROM products p INNER JOIN suppliers s ON p.SupplierID = s.SupplierID 
        WHERE p.SupplierID = $id";
$sql_supplier = "SELECT CompanyName FROM suppliers WHERE SupplierID = $id";

$result = $connect->query($sql);
$result_supplier = $connect->query($sql_supplier);
$company = $result_supplier->fetch_all()[0][0];
?>

<p>2. Buatlah program PHP untuk page produk seperti yang disebutkan pada soal nomor 1!</p>
<a href="uas_22_23_no_1.php">Kembali</a>
<h1>Daftar Produk</h1>
<p>Oleh supplier: <?= $company ?></p>
<table>
  <tr>
    <th>Produk ID</th>
    <th>Nama Produk</th>
    <th>Harga</th>
  </tr>
  <?php while ($row = $result->fetch_object()) : ?>
    <tr>
      <td><?= $row->ProductID ?></td>
      <td><?= $row->ProductName ?></td>
      <td><?= $row->UnitPrice ?></td>
    </tr>
  <?php endwhile ?>
</table>