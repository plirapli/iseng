// Import Modul
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = process.env.PORT || '3001';

app.set('views', './views');
app.set('view engine', 'pug');

// Untuk keperluan upload data dari form
app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', function (req, res) {
  res.send('Contoh Express 1, URL Utama');
});

app.get('/contoh-2/:num1/:num2', function (req, res) {
  const num1 = parseInt(req.params.num1);
  const num2 = parseInt(req.params.num2);
  const hasil = num1 + num2;

  res.render('contoh_2', { num1, num2, hasil });
});

// menanpilkan contoh form
app.get('/contoh-form', (req, res) => {
  res.render('contoh_form');
});

// memproses form
app.post('/proses-form', (req, res) => {
  console.log(req.body);

  // kirim data form ke UI
  res.render('proses_form', {
    nama: req.body.nama,
    alamat: req.body.alamat,
    kota: req.body.kota,
  });
});

app.listen(port, () => {
  console.log('Server jalan di port ' + port);
});
