const solution = (str) => {
  return str.split('').map(s => s == s.toUpperCase() ? ` ${s}` : s).join('')
}

console.log(solution('camelCasing'), 'camel Casing', 'Unexpected result')
console.log(solution('camelCasingTest'), 'camel Casing Test', 'Unexpected result')