<html>
<?php
$serverdb = "localhost";
$username = "admin";
$password = "Admin123*";
$db = "toko2";
$mydb = new mysqli($serverdb, $username, $password, $db);
?>

<body>
    <?php

    $sql = "select * from products";
    $produk = $mydb->query($sql);

    ?>

    <h1>Product List</h1>
    <table border="1">

        <?php

        while ($row = $produk->fetch_object()) {
            //print $row->productCode." | ". $row->productName. " | ". $row->buyPrice;
            //print "<br>";
        ?>

            <tr>
                <td><?= $row->productCode ?></td>
                <td><?= $row->productName ?></td>
                <td><?= $row->buyPrice ?></td>
            </tr>

        <?php

        }
        ?>


    </table>


</body>

</html>