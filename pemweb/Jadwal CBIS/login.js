import { proxy } from './config/config.js';
import { domParser } from './utils/utils.js';

const baseURL = proxy + 'http://fti.upnyk.ac.id';

fetch(`${baseURL}/login.html`, {
  headers: {
    Accept: 'text/html',
    'Content-Type': 'application/x-www-form-urlencoded',
  },
  body: 'user_id=123210078&pwd0=15sepuluh&fcaptcha=1&submit1=Login',
  method: 'POST',
  credentials: 'include',
})
  .then((res) => {
    console.log(res.headers.get('Set-Cookie'));
    return res.text();
  })
  .then((data) => {
    const doc = domParser(data);

    // Bikin url
    const session = doc
      .querySelector('frame[name="menusdm"]')
      .src.split('/')[4];
    const url = `${baseURL}/session/${session}/menusdm.html`;

    // Set Cookies
    const path = `/session/${session}/`;
    console.log(path);

    document.cookie = `sessiondir=session%2F${session}; path=${path};`;
    // cookie_stamp=a2628d176cbb52eacf92ca268e2f1d6e;;
    // namauserck=MUHAMMAD+RAFLI;
    // user_idck_mhs=aVQ0T1l0WEdhQ014UVI4NjV6cDcrQT09;
    // user_idck=123210078;
    // statusck=0;
    // psmhs_idck=123;
    // document.cookie = `waktif=1673977743;`;
    // document.cookie = `path=${path};`;

    fetch(url, { headers: { Accept: 'text/html' }, method: 'GET' })
      .then((res) => res.text())
      .then((data) => console.log(data));
  });
