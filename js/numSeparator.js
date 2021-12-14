const thousandSeparator = (num) => {
  const arr = num
    .toString()
    .split("")
    .reverse()
    .map((n, i) => (i % 3 === 0 ? n + "." : n))
    .reverse();

  return arr
    .map((n, i) =>
      i + 1 === arr.length ? n.split("").slice(0, 1).join("") : n
    )
    .join("");
};

console.log(thousandSeparator(1000));
console.log(thousandSeparator(100000));
console.log(thousandSeparator(1000000));
console.log(thousandSeparator(100));
console.log(thousandSeparator(100000000000000000));
