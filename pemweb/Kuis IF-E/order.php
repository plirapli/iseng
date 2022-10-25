<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
</head>

<body style="min-height: 100vh;" class="p-5 container">
  <div class="row">
    <form method="POST" action="result.php" class="col-sm-8">
      <div class="mb-3">
        <label for="productInput" class="form-label">Product</label>
        <input type="text" name="product" class="form-control" id="productInput" placeholder="Sports Wear" required>
      </div>
      <div class="mb-3">
        <label for="selectCat">
          Category
        </label>
        <select name="category" class="form-select" id="selectCat" aria-label="Select Category" required>
          <option selected value="">Category</option>
          <option value="Gadget">Gadget</option>
          <option value="Health">Health</option>
          <option value="Food and Drink">Food and Drink</option>
          <option value="Sport">Sport</option>
        </select>
      </div>
      <div class="mb-3 d-flex gap-4">
        <div class="w-100">
          <label for="priceInput" class="form-label">Price</label>
          <input type="number" name="price" class="form-control" id="priceInput" placeholder="15000" required>
        </div>
        <div class="w-100">
          <label for="qtyInput" class="form-label">Qty</label>
          <input type="number" name="qty" class="form-control" id="qtyInput" placeholder="1" required>
        </div>
      </div>
      <div class="mb-3">
        <label for="paymentRadio">Payment</label>
        <div class="form-check">
          <input class="form-check-input" type="radio" name="payment" value="Cash" id="cashRadio" required>
          <label class="form-check-label" for="cashRadio">
            Cash
          </label>
        </div>
        <div class="form-check">
          <input class="form-check-input" type="radio" name="payment" value="Credit Card" id="creditRadio" checked>
          <label class="form-check-label" for="creditRadio">
            Credit Card
          </label>
        </div>
        <div class="form-check">
          <input class="form-check-input" type="radio" name="payment" value="Debit Card" id="debitRadio">
          <label class="form-check-label" for="debitRadio">
            Debit Card
          </label>
        </div>
      </div>
      <div class="mb-3">
        <label for="noteTextArea" class="form-label">Note</label>
        <textarea name="note" class="form-control" id="noteTextArea" rows="2" placeholder="Colors (Red, Black, and Navy)"></textarea>
      </div>
      <button type="submit" class="mt-4 w-100 btn btn-outline-dark">
        Buy
      </button>
    </form>
    <div class="col-sm-4">
      <img class="w-100" src="./img/card.png" alt="">
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-OERcA2EqjJCMA+/3y+gxIOqMEjwtxJY7qPCqsdltbNJuaOe923+mo//f6V8Qbsw3" crossorigin="anonymous"></script>
</body>

</html>