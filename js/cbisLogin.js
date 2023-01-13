if (
  window.location.href == 'http://fti.upnyk.ac.id/login.html' ||
  window.location.href == 'http://fti.upnyk.ac.id/menu01.html?login=fail'
) {
  const PIN = 'PIN';
  const NIM = 'NIM';

  const nimEl = document.querySelector("input[name='user_id']");
  const pinEl = document.querySelector("input[name='pwd0']");
  const captcha = document.querySelector("input[name='fcaptcha']");
  const form = document.querySelector('form');

  // Dapetin nim sama pin dari local storage
  const nim = localStorage.getItem(NIM);
  let pin = localStorage.getItem(PIN);

  let pinVal;
  if (pin < 10) pinVal = '000' + pin;
  else if (pin < 100) pinVal = '00' + pin;
  else if (pin < 1000) pinVal = '0' + pin;

  if (nimEl) {
    // Ngubah value form
    nimEl.value = nim;
    captcha.value = 1;
    pinEl.value = pinVal;

    if (typeof Storage !== undefined) localStorage.setItem(PIN, pin);
    pin++;
    form.submit();
  }
}
