<?php
echo "<b>UAS 2022/2023</b> <br>" .
  "<a href='uas_21_22.php'>UAS 2021/2022</a> <br>" .
  "<a href='uts_22_23.php'>UTS 2022/2023</a>";
echo "<h2>UAS 2022/2023</h2>";

$connect = new mysqli('localhost', 'root', '', 'nwind');

// NO. 1
$sql = 'SELECT * FROM suppliers';
$result = $connect->query($sql); ?>

<p>
  1. Buatlah program PHP untuk menampilkan data Supplier dan link "Lihat Produk" untuk menuju ke page produk yang disupply oleh supplier tersebut!
</p>
<h1>Daftar Supplier</h1>
<table>
  <tr>
    <th>Supplier ID</th>
    <th>Nama Perusahaan</th>
    <th>Alamat</th>
    <th>Kota</th>
    <th>Telepon</th>
    <th></th>
  </tr>
  <?php while ($row = $result->fetch_object()) : ?>
    <tr>
      <td><?= $row->SupplierID ?></td>
      <td><?= $row->CompanyName ?></td>
      <td><?= $row->Address ?></td>
      <td><?= $row->City ?></td>
      <td><?= $row->Phone ?></td>
      <td>
        <a href="uas_22_23_no_2.php?id=<?= $row->SupplierID ?>">
          <button type="button">
            Lihat Produk
          </button>
        </a>
      </td>
    </tr>
  <?php endwhile ?>
</table>