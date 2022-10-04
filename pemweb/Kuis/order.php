<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Kuis</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
</head>

<body style="min-height: 100vh;" class="p-5 d-flex align-items-start gap-5">
  <img src="./img/order.png" alt="">
  <div class="flex-grow-1 d-flex flex-column justify-content-center align-items-center">
    <form action="result.php" method="POST" class="w-100">
      <div class="mb-3">
        <label for="menuInput" class="form-label">Menu</label>
        <input type="text" name="menu" class="form-control" id="menuInput" placeholder="Neapolitan Pizza" required>
      </div>
      <div class="mb-3">
        <label for="selectCategory">Category</label>
        <select name="cat" class="form-select mt-1" id="selectCategory" aria-label="Select Category" required>
          <option selected value="">Category</option>
          <option value="Drink">Drink</option>
          <option value="Food">Food</option>
          <option value="Other">Other</option>
        </select>
      </div>
      <div class="mb-3">
        <label for="priceInput" class="form-label">Price</label>
        <input type="number" name="price" class="form-control" id="priceInput" placeholder="75000" required>
      </div>
      <div class="mb-3">
        <label for="discInput" class="form-label">Discount</label>
        <input type="number" name="disc" class="form-control" id="discInput" placeholder="12000" required>
      </div>
      <div class="mb-3">
        <div class="form-check">
          <input class="form-check-input" type="radio" name="orderType" id="dineInRadio" required>
          <label class="form-check-label" for="dineInRadio">
            Dine in
          </label>
        </div>
        <div class="form-check">
          <input class="form-check-input" type="radio" name="orderType" id="takeAwayRadio" checked>
          <label class="form-check-label" for="takeAwayRadio">
            Take away
          </label>
        </div>
      </div>
      <div class="mb-3">
        <label for="noteTextArea" class="form-label">Note</label>
        <textarea class="form-control" name="note" id="noteTextArea" rows="2" placeholder="Extra Cheese"></textarea>
      </div>
      <div class="mt-5">
        <button type="submit" class="btn btn-outline-dark w-100">Submit</button>
      </div>
    </form>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-OERcA2EqjJCMA+/3y+gxIOqMEjwtxJY7qPCqsdltbNJuaOe923+mo//f6V8Qbsw3" crossorigin="anonymous"></script>
</body>

</html>