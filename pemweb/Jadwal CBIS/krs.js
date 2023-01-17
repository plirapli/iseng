// Buat Tukeran jadwal Arsi & Prak. PBO
const ePrakPboInput = document.querySelector(
  'input[name="ap[IF21|123210321][IF-E]"]'
);

if (ePrakPboInput) {
  const form = document.querySelector('form');

  // Init input element
  const dArsiInput = document.querySelector(
    'input[name="ap[IF21|123210293][IF-D]"]'
  );
  const eArsiInput = document.querySelector(
    'input[name="ap[IF21|123210293][IF-E]"]'
  );
  const dPrakPboInput = document.querySelector(
    'input[name="ap[IF21|123210321][IF-D]"]'
  );

  // Tukeran jadwal
  const conditionArsi = dArsiInput.checked || !eArsiInput.checked;
  const conditionPrakPBO = dPrakPboInput.checked || !ePrakPboInput.checked;

  if (conditionArsi && conditionPrakPBO) {
    // Uncheck arsi d & prak pbo d
    dArsiInput.checked = false;
    dPrakPboInput.checked = false;

    // Check arsi e & e
    eArsiInput.checked = true;
    ePrakPboInput.checked = true;
    form.submit();
  }
}

// Buat auto click PBO IF-E
const ePboInput = document.querySelector(
  'input[name="ap[IF21|123210303][IF-E]"]'
);

if (ePrakPboInput) {
  const form = document.querySelector('form');
  // Centang PBO IF-E
  if (!ePboInput.checked) {
    ePboInput.checked = true;
    form.submit();
  }
}
