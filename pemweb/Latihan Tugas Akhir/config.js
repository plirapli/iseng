const config = {
  db: {
    /* don't expose password or any sensitive info, done only for demo */
    host: process.env.HOST,
    user: process.env.USERNAME,
    password: process.env.PASSWORD,
    database: process.env.DATABASE,
  },
  listPerPage: 10,
};
module.exports = config;