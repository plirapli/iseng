const table = document.querySelector('table');
const domParser = (text) => {
  const parser = new DOMParser();
  return parser.parseFromString(text, 'text/html');
};

// Fetch jadwal
fetch('http://127.0.0.1:8080/http://fti.upnyk.ac.id/carijadwal.html', {
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded',
    Accept: 'text/html',
  },
  referrer: 'http://fti.upnyk.ac.id/carijadwal.html',
  body: 'thn_sid=2022|2|SEMESTER GENAP|123&submit1=CARI',
  method: 'POST',
})
  .then((res) => res.text())
  .then((data) => {
    const selectedMK = [
      '100210153',
      '123210252',
      '123210263',
      '123210273',
      '123210283',
      '123210293',
      '123210303',
      '123210311',
      '123210321',
      '100210082',
    ];
    const condition = (kode) => {
      return selectedMK.some((mk) => mk === kode);
    };

    // Convert the HTML string into a document object
    const doc = domParser(data);

    // Table
    const tableBody = doc.querySelectorAll('table tbody')[0];
    const tableUjianBody = doc.querySelectorAll('table tbody')[1];

    const cells = [...tableBody.querySelectorAll('.cell')];
    const cellsUjian = [...tableUjianBody.querySelectorAll('.cell')];

    let filteredCellsEl = '',
      filteredCellsUjianEl = '';

    if (cells.length) {
      for (const cell of cells) {
        const [, jurusan, kode, nama, sks, kelas, , hari, jam, ruangan, dosen] =
          Array.from(
            cell.querySelectorAll('td'),
            (cellText) => cellText.textContent
          );

        if (condition(kode) && jurusan === 'INFORMATIKA' && kelas !== 'IF-H') {
          const element = `
            <tr class="cell">
              <td class="text-center">${kode}</td>
              <td class="text-center">${sks}</td>
              <td>${nama}</td>
              <td class="text-center">${kelas}</td>
              <td class="text-center">${hari}</td>
              <td class="text-center">${jam}</td>
              <td class="text-center">${ruangan}</td>
              <td>${dosen}</td>
            </tr>`;
          filteredCellsEl += element;
        }
      }

      for (const cell of cellsUjian) {
        let [, kode, nama, sks, kelas, ...info] = Array.from(
          cell.querySelectorAll('td'),
          (cellText) => cellText.textContent
        );

        kode = kode.split(' ')[0];

        if (condition(kode) && kelas !== 'IF-H') {
          const element = `
            <tr class="cell">
              <td style='padding: 0.5rem'>${kode}</td>
              <td style='padding: 0.5rem'>${sks} - ${nama}</td>
              <td style='padding: 0.5rem'>${kelas}</td>
            </tr>`;
          filteredCellsUjianEl += element;
        }
      }

      const tableHead = `
        <tr>
          <th class="text-center">Kode MK</th>
          <th class="text-center">SKS</th>
          <th>Nama MK</th>
          <th class="text-center">Kelas</th>
          <th class="text-center">Hari</th>
          <th class="text-center">Jam</th>
          <th class="text-center">Ruangan</th>
          <th>Pasangan</th=>
        </tr>`;

      const tableUjianHead = `
        <tr class="header hijau">
          <th>KODE MK</th>
          <th>SKS - NAMA MK</th>
          <th>KELAS</th>
        </tr>`;

      tableBody.innerHTML = tableHead + filteredCellsEl;
      tableUjianBody.innerHTML = tableUjianHead + filteredCellsUjianEl;
      let tableEl = `
        <table class="table table-striped">
          ${tableBody.innerHTML}
        </table>
      `;

      table.innerHTML = tableEl;
    }
  });

// // Fetch login
// fetch('http://127.0.0.1:8080/http://fti.upnyk.ac.id/login.html', {
//   headers: {
//     Accept: 'text/html',
//     'Content-type': 'application/x-www-form-urlencoded',
//   },
//   body: 'user_id=123210078&pwd0=15sepuluh&fcaptcha=1&submit1=Login',
//   method: 'POST',
// })
//   .then((res) => res.text())
//   .then((data) => {
//     const doc = domParser(data);
//     const session = doc.querySelector('frame').src.split('/')[4];
//     const url = `http://127.0.0.1:8080/http://fti.upnyk.ac.id/session/${session}/transkrip.html`;
//     console.log(url);

//     fetch(url, {
//       headers: { Accept: 'text/html' },
//       method: 'GET',
//       mode: 'cors',
//     })
//       .then((res) => res.text())
//       .then((data) => console.log(data));
//   });
