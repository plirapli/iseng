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

const tableBody = document.querySelector('table tbody');
const tableHead = document.querySelector('table thead');
const cells = [...document.querySelectorAll('.cell')];
let filteredCellsEl = '';

for (const cell of cells) {
  const jurusan = cell.querySelector('td:nth-child(2)').textContent;
  const kode = cell.querySelector('td:nth-child(3)').textContent;
  const nama = cell.querySelector('td:nth-child(4)').textContent;
  const sks = cell.querySelector('td:nth-child(5)').textContent;
  const kelas = cell.querySelector('td:nth-child(6)').textContent;
  const hari = cell.querySelector('td:nth-child(8)').textContent;
  const jam = cell.querySelector('td:nth-child(9)').textContent;
  const ruangan = cell.querySelector('td:nth-child(10)').textContent;
  const dosen = cell.querySelector('td:nth-child(11)').textContent;
  const condition =
    selectedMK.some((mk) => mk === kode) &&
    jurusan === 'INFORMATIKA' &&
    kelas !== 'IF-H';

  if (condition) {
    const element = `
      <tr class="cell">
        <td>${kode}</td>
        <td>${sks} - ${nama}</td>
        <td>${kelas}</td>
        <td>${hari}</td>
        <td>${jam}</td>
        <td>${ruangan}</td>
        <td>${dosen}</td>
      </tr>
    `;
    filteredCellsEl += element;
  }
}

tableHead.innerHTML = `
  <tr class="header hijau">
    <th>Kode MK</th>
    <th>Nama MK</th>
    <th>Kls</th>
    <th>Hari</th>
    <th>Jam</th>
    <th>Ruangan</th>
    <th>Pasangan</th>
  </tr>
`;
tableBody.innerHTML = filteredCellsEl;
