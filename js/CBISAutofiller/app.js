const STORAGE_KEY = 'PIN';
const nimEl = document.querySelector("input[name='user_id']");
const pinEl = document.querySelector("input[name='pwd0']");
const captcha = document.querySelector("input[name='fcaptcha']");
const form = document.querySelector('form');

let i = localStorage.getItem(STORAGE_KEY);
if (!i) i = 0;

if (nimEl) {
  let pin;
  nimEl.value = 123210166;
  captcha.value = 1;

  if (i < 10) pin = '000' + i;
  else if (i < 100) pin = '00' + i;
  else if (i < 1000) pin = '0' + i;
  else pin = i;

  pinEl.value = localStorage.getItem(STORAGE_KEY);
  form.submit();
} else {
  i++;
  console.log('error');
}

if (typeof Storage !== undefined) {
  localStorage.setItem(STORAGE_KEY, parsedData);
}
console.log(pin);

const urlList = ['login.html', 'menu01.html?login=fail'];
