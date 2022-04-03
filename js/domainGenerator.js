const domainGenerator = (name) => {
  let domain = name
    .split(' ')
    .map((char) =>
      char
        .split('')
        .filter((char) => /[a-zA-Z]/.test(char))
        .join('')
        .substring(0, name.length < 20 ? name.length : 1)
        .toLowerCase()
    )
    .join('');

  return 'https://' + domain + '.com/';
};

console.log(domainGenerator('Muhammad Rafli Y.'));
console.log(domainGenerator('Sergio "/Kun"/ Aguero'));
