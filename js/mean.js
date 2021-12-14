const getAverage = (arr) => {
  const total = arr.reduce((acc, val) => acc + val)
  return Math.floor(total / arr.length)
}

console.log(getAverage([2,2,2,2]),2);
console.log(getAverage([1,2,3,4,5,]),3);
console.log(getAverage([1,1,1,1,1,1,1,2]),1);