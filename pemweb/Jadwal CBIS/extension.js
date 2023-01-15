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

const table = document.querySelector('table');
const tableBody = document.querySelectorAll('table tbody')[0];
const tableUjianBody = document.querySelectorAll('table tbody')[1];
const cells = [...tableBody.querySelectorAll('.cell')];
const cellsUjian = [...tableUjianBody.querySelectorAll('.cell')];

let filteredCellsEl = '',
  filteredCellsUjianEl = '';

if (cells.length) {
  table.style.width = '100%';

  for (const cell of cells) {
    const [, jurusan, kode, nama, sks, kelas, , hari, jam, ruangan, dosen] =
      Array.from(
        cell.querySelectorAll('td'),
        (cellText) => cellText.textContent
      );

    if (condition(kode) && jurusan === 'INFORMATIKA' && kelas !== 'IF-H') {
      const element = `
        <tr class="cell">
          <td style='padding: 0.5rem;'>${kode}</td>
          <td style='padding: 0.5rem;'>${sks} - ${nama}</td>
          <td style='padding: 0.5rem;'>${kelas}</td>
          <td style='padding: 0.5rem;'>${hari}</td>
          <td style='padding: 0.5rem;'>${jam}</td>
          <td style='padding: 0.5rem;'>${ruangan}</td>
          <td style='padding: 0.5rem;'>${dosen}</td>
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
    <tr class="header hijau">
      <th style="padding: 0.5rem">Kode MK</th>
      <th style="padding: 0.5rem">SKS - Nama MK</th>
      <th style="padding: 0.5rem">Kls</th>
      <th style="padding: 0.5rem">Hari</th>
      <th style="padding: 0.5rem">Jam</th>
      <th style="padding: 0.5rem">Ruangan</th>
      <th style="padding: 0.5rem">Pasangan</th>
    </tr>`;

  const tableUjianHead = `
    <tr class="header hijau">
      <th>KODE MK</th>
      <th>SKS - NAMA MK</th>
      <th>KELAS</th>
    </tr>`;

  tableBody.innerHTML = tableHead + filteredCellsEl;
  tableUjianBody.innerHTML = tableUjianHead + filteredCellsUjianEl;
}
