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
