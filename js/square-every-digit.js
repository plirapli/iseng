const squareDigits = (num) => parseInt(num.toString().split('').map(n => parseInt(n * n)).join(''))

console.log(squareDigits(9119), 811181);
