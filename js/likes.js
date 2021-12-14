// function likes(names) {
//   if(names.length >= 1) {
//     if(names.length == 1) {
//       return `${names[0]} likes this`
//     } else if (names.length == 2) {
//       return `${names[0]} and ${names[1]} like this`
//     } else {
//       if(names.length > 3) {
//         return `${names[0]}, ${names[1]} and ${names.length - 2} others like this`
//       } else {
//         return `${names[0]}, ${names[1]} and ${names[2]} like this`
//       }
//     }
//   } else {
//     return `no one likes this`
//   }
// }

// console.log(likes([]), 'no one likes this')
// console.log(likes(['Peter']), 'Peter likes this')
// console.log(likes(['Jacob', 'Alex']), 'Jacob and Alex like this')
// console.log(likes(['Max', 'John', 'Mark']), 'Max, John and Mark like this')
// console.log(likes(['Alex', 'Jacob', 'Mark', 'Max']), 'Alex, Jacob and 2 others like this')

// const positiveSum = (array) => {
//   return array.filter(arr => arr >= 0).reduce((acc, val) => acc + val, 0)
// }

// console.log(positiveSum([1,2,3,4,5]),15);
// console.log(positiveSum([-1,-2,-3,-4,-5]),0);
// console.log(positiveSum([-1,2,3,4,-5]),9);

// function openOrSenior(data){
//   let allArr = []
//   for (let i = 0; i < data.length; i++) {
//     let newArr = data[i][0] >= 55 && data[i][1] > 7 ? 'Senior' : 'Open'
//     allArr.push(newArr)
//   }
//   return allArr
// }

// console.log(openOrSenior([[45, 12],[55,21],[19, -2],[104, 20]]),['Open', 'Senior', 'Open', 'Senior'])

// function DNAStrand(dna){
//   return dna.split('').map(d => {
//     switch (d) {
//       case 'A': d = 'T'
//         break;
//       case 'T': d = 'A'
//         break;
//       case 'C': d = 'G'
//         break;
//       case 'G': d = 'C'
//         break;
//     }
//     return d
//   }).join('')
// }

// let pairs = {'A':'T','T':'A','C':'G','G':'C'};

// function DNAStrand(dna){
//   return dna.split('').map(v => pairs[v]).join('');
// }

// console.log(DNAStrand("AAAA"),"TTTT","String AAAA is");
// console.log(DNAStrand("ATTGC"),"TAACG","String ATTGC is");
// console.log(DNAStrand("GTAT"),"CATA","String GTAT is");

// function getCount(str) {
//   let vowelsCount = 0;
//   let vowels = ['a', 'i', 'u', 'e', 'o']
  
//   str.split('').forEach(s => {
//     vowels.forEach(vow => {
//       vowelsCount += vow === s ? 1 : 0
//     })  
//   });
  
//   return vowelsCount;
// }

// console.log(getCount('tes'), 5)

// function oddOrEven(array) {
//   if(array.length == 0) {
//     return 'even'
//   }
//   return array.reduce((acc, val) => acc + val) % 2 === 0 ? 'even' : 'odd'
// }

// console.log(oddOrEven([], 'even'))

// const genres = "Adventure, Drama, Fantasy, Mystery"

// const setGenres = () => {
//   genres.split(', ')
// }

// console.log(setGenres())

const dur = '130 min'

const convDur = () => {
  const newInt = parseInt(dur)
  const h = Math.floor(newInt/60)
  const m = newInt % 60
  return `${h}h ${m}m`
}

console.log(convDur())