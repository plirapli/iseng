const mysql = require('mysql');
require('dotenv').config();

const config = {
  /* don't expose password or any sensitive info, done only for demo */
  host: process.env.HOST,
  user: process.env.USER,
  password: process.env.PASSWORD,
  database: process.env.DATABASE,
};

// Konfigurasi Koneksi
const connection = mysql.createConnection({
  ...config,
  multipleStatements: true,
});

// Koneksi DB
connection.connect((err) => {
  if (err) throw err;
  console.log('MySQL Connected...');
});

module.exports = connection;
