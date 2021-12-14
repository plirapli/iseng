const euclidan = (pointA, pointB) => {
  return (
    pointA
      .map((x, i) => {
        const y = pointB[i];
        return Math.pow(x - y, 2);
      })
      .reduce((prevVal, currentVal) => prevVal + currentVal) **
    (1 / 2)
  );
};

console.log(euclidan([2, 8, -2], [5, 6, 0]));
