const expandedForm = (num) => {
  const arr = num.toString().split('').reverse().map(a => parseInt(a))
  return arr.map((a, i) => a * Math.pow(10, i)).reverse().filter(a => a !== 0).join(' + ')
}

console.log(expandedForm(12), '10 + 2');
console.log(expandedForm(42), '40 + 2');
console.log(expandedForm(70304), '70000 + 300 + 4');