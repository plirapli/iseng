// CPP program to illustrate Affine Cipher

#include <iostream>
#include <algorithm>
using namespace std;

string affine_encrypt(string text, int shiftKey, int coprime)
{
  string encrypted_text = "";

  for (int i = 0; i < text.length(); i++)
  {
    if (isalpha(text[i]))
    {
      char huruf = text[i];
      char base = (islower(huruf)) ? 'a' : 'A'; // nentuin huruf besar apa kecil

      // Distandarisasi dulu dari ASCII jadi angke ke berapa di alphabet
      int standarized_huruf = huruf - base;
      int result = (coprime * standarized_huruf + shiftKey) % 26; // operasi affine cipher
      text[i] = result + base;                                    // ubah dari alphabet ke ASCII
    }
    encrypted_text += text[i]; // huruf hasil enkripsi di push nyampe bentuk teks
  }
  return encrypted_text;
}

string affine_decrypt(string text, int shiftKey, int coprime)
{
  string decrypted_text = "";
  int coprime_inv = 0;

  // Nyari multiplicative inverse antara coprime dengan 26
  for (int i = 0; i < 26; i++)
  {
    // Cek apakah (a * i) % 26 == 1,
    // Kalo iya, itu hasilnya
    if (((coprime * i) % 26) == 1)
      coprime_inv = i;
  }
  for (int i = 0; i < text.length(); i++)
  {
    if (isalpha(text[i]))
    {
      char huruf = text[i];
      char base = (islower(huruf)) ? 'a' : 'A'; // nentuin huruf besar apa kecil

      // Distandarisasi dulu dari ASCII jadi angke ke berapa di alphabet
      int standarized_huruf = huruf - base;

      // Operasi affine cipher
      int result = (coprime_inv * (standarized_huruf - shiftKey));
      result = ((result % 26) + 26) % 26;

      text[i] = result + base; // ubah dari alphabet ke ASCII
    }
    decrypted_text += text[i]; // huruf hasil enkripsi di push nyampe bentuk teks
  }
  return decrypted_text;
}

// buat ngecek key valid apa engga
bool isKeyValid(string key)
{
  bool isValid = true;
  // ngecek key valid apa engga
  if (key.size() > 1 && (int)key[0] == 48)
    isValid = false;

  for (int i = 0; i < key.size(); i++)
  {
    int keyInAscii = (int)key[i];
    if (!(keyInAscii >= 48 && keyInAscii <= 57))
    {
      isValid = false;
      break;
    }
  }
  return isValid;
}

bool isCoprime(int key)
{
  return __gcd(26, key) == 1;
}

int main(void)
{
  bool isShiftKeyNum, isCoprimeNum;
  string inputText, inputCoprime, inputShiftKey;

  cout << "Caesar Cipher \n";
  cout << "Masukkan teks: ";
  // cin.ignore();
  getline(cin, inputText);
  cout << "Masukkan jumlah pergeseran: ";
  getline(cin, inputShiftKey);
  cout << "Masukkan bilangan yg relatif prima dengan 26: ";
  getline(cin, inputCoprime);
  cout << endl;

  isShiftKeyNum = isKeyValid(inputShiftKey);
  isCoprimeNum = isKeyValid(inputCoprime);

  if (isShiftKeyNum && isCoprimeNum)
  {
    bool validCoprime = isCoprime(stoi(inputCoprime));

    if (validCoprime)
    {
      int shiftKey = stoi(inputShiftKey);
      int coprime = stoi(inputCoprime);
      string cipherText = affine_encrypt(inputText, shiftKey, coprime);
      string plainText = affine_decrypt(cipherText, shiftKey, coprime);

      cout << "Cipher Text: \n"
           << cipherText << "\n\n";
      cout << "Plain Text: \n"
           << plainText << "\n";
    }
    else
    {
      cout << "Bilangan " << inputCoprime << " tidak relatif prima dengan 26";
    }
  }
  else
  {
    cout << "Kunci tidak valid";
  }

  return 0;
}