// Import Modul
require('dotenv').config();
const express = require('express');
const bodyParser = require('body-parser');
const connection = require('./config/database');
const app = express();
const port = process.env.PORT || '3001';

app.set('views', './views');
app.set('view engine', 'pug');

// Untuk keperluan upload data dari form
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.get('/', (req, res) => {
  // buat query sql
  const command = 'SELECT * FROM categories';

  // Querying
  connection.query(command, (err, results, field) => {
    // Error handling
    if (err) {
      return res.status(500).json({ message: 'Ada kesalahan', error: err });
    }

    // jika request berhasil
    // res.status(200).json({ data: results });
    res.render('kategori', { results });
  });
});

app.get('/:category', (req, res) => {
  // buat query sql
  const category = req.params.category;
  const command = `SELECT * FROM products WHERE CategoryID = ${category}`;

  // Querying
  connection.query(command, (err, results, field) => {
    // Error handling
    if (err) {
      return res.status(500).json({ message: 'Ada kesalahan', error: err });
    }

    // jika request berhasil
    // res.status(200).json({ data: results });
    res.render('produk', { results });
  });
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
