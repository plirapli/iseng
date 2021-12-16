const dateFixed = (date) => {
  const d = String(date.getDate()).padStart(2, '0');
  const m = String(date.getMonth() + 1).padStart(2, '0'); // + 1 karena jan = 0
  const y = date.getFullYear();

  return d + '-' + m + '-' + y;
};

const dateNow = new Date();

console.log(dateFixed(dateNow));
