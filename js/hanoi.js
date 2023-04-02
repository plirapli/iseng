const hanoi = (n, A, B, C) => {
  if (n == 1)
    console.log('Pindahkan piringan dari ' + A + ' ke ' + C)
  else {

    hanoi(n - 1, A, C, B) // T(n-1)
    console.log('Pindahkan piringan dari ' + A + ' ke ' + C)
    hanoi(n - 1, B, A, C) // T(n-1)
  }
}

hanoi(3, 'A', 'B', 'C');