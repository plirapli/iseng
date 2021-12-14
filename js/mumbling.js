function accum(s) {
  let total = ''
  const arr = s.split('')

  for (let i = 0; i < arr.length; i++) {
    let totalArr = ''
    if (i === arr.length - 1) {
      for (let j = 0; j <= i; j++) {
        if(j !== 0) {
          totalArr += arr[i].toLowerCase()
        } else {
          totalArr += arr[i].toUpperCase()
        }
      }

      total += totalArr
    } else {
      for (let j = 0; j <= i; j++) {
        if(j !== 0) {
          totalArr += arr[i].toLowerCase()
        } else {
          totalArr += arr[i].toUpperCase()
        }
      }
      total += `${totalArr}-`
    }
  }
  return total
}
   
console.log(accum("ZpglnRxqenU"), "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
console.log(accum("NyffsGeyylB"), "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
console.log(accum("MjtkuBovqrU"), "M-Jj-Ttt-Kkkk-Uuuuu-Bbbbbb-Ooooooo-Vvvvvvvv-Qqqqqqqqq-Rrrrrrrrrr-Uuuuuuuuuuu");
console.log(accum("EvidjUnokmM"), "E-Vv-Iii-Dddd-Jjjjj-Uuuuuu-Nnnnnnn-Oooooooo-Kkkkkkkkk-Mmmmmmmmmm-Mmmmmmmmmmm");
console.log(accum("HbideVbxncC"), "H-Bb-Iii-Dddd-Eeeee-Vvvvvv-Bbbbbbb-Xxxxxxxx-Nnnnnnnnn-Cccccccccc-Ccccccccccc");