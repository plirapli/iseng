// Import Modul
require('dotenv').config();
const express = require('express');
const cookieParser = require('cookie-parser');
const sessions = require('express-session');
const connection = require('./config/database');

// Init express app
const app = express();
const port = process.env.PORT || '3001';

// Set session expire
const maxAge =
  //session middleware
  app.use(
    sessions({
      secret: '1234567890',
      saveUninitialized: false,
      resave: false,
      cookie: {
        secure: false,
        expires: false,
        maxAge: 24 * 60 * 60 * 1000,
      },
    })
  );

app.set('views', './views');
app.set('view engine', 'pug');

// Untuk keperluan upload data dari form
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

/* ROUTES */
app.get('/', (req, res) => {
  // buat query sql
  const command = 'SELECT * FROM categories';
  console.log(req.session);

  // Querying
  connection.query(command, (err, results, field) => {
    // Error handling
    if (err) {
      return res.status(500).json({ message: 'Ada kesalahan', error: err });
    }
    // jika request berhasil
    res.render('kategori', { results });
  });
});

app.get('/kategori/:category', (req, res) => {
  // buat query sql
  const category = req.params.category;
  const command = `SELECT * FROM products WHERE CategoryID = ${category}`;

  // Query
  connection.query(command, (err, results, field) => {
    // Error handling
    if (err) {
      return res.status(500).json({ message: 'Ada kesalahan', error: err });
    }
    res.render('produk', { results });
  });
});

app.get('/produk/:productId', (req, res) => {
  // buat query sql
  const product = req.params.productId;
  const command = `SELECT * FROM products p 
                   INNER JOIN categories c ON p.CategoryID = c.CategoryID 
                   INNER JOIN suppliers s ON p.SupplierID = s.SupplierID
                   WHERE ProductID = ${product}`;

  // Querying
  connection.query(command, (err, results, field) => {
    // Error handling
    if (err) {
      return res.status(500).json({ message: 'Ada kesalahan', error: err });
    }

    // jika request berhasil
    res.render('produk_detail', { product: results[0] });
  });
});

const Carts = [];

// memproses form
app.post('/proses-cart', (req, res) => {
  Carts.push(req.body);

  req.session.cart = JSON.stringify(Carts);
  res.redirect('/');
});

app.get('/shopping-cart', (req, res) => {
  const sessionCart = req.session.cart;
  const shoppingCart = JSON.parse(sessionCart);

  res.render('cart', { shoppingCart });
});
/* END ROUTES */

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
