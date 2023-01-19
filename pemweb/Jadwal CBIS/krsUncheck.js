// Buat Tukeran jadwal Arsi IF-D ke IF-E
const eArsiInput = document.querySelector(
  'input[name="ap[IF21|123210293][IF-E]"]'
);

if (eArsiInput) {
  const form = document.querySelector('form');

  // Init input element
  const dArsiInput = document.querySelector(
    'input[name="ap[IF21|123210293][IF-D]"]'
  );

  // Tukeran kelas
  const eArsiKuota =
    eArsiInput.parentElement.parentElement.children[5].textContent;
  const conditionArsi = parseInt(eArsiKuota);

  if (conditionArsi) {
    // Uncheck arsi d & prak pbo d
    dArsiInput.checked = false;
    eArsiInput.checked = true;

    form.submit();
  } else if (!eArsiInput.checked) {
    form.submit();
  }
}
