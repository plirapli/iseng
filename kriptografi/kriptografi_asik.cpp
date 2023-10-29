#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Caesar Cipher
void caesar();
string caesar_decrypt(string text, int key);
string caesar_encrypt(string text, int key);
bool caesar_isKeyValid(string key);

// Vigenere Cipher
void vigenere();
string vigenere_generate_key(string text, string keyword);
string vigenere_encrypt(string text, string key);
string vigenere_decrypt(string cipherText, string key);
bool vigenere_isKeyValid(string keyword);
bool isLowercase(int asciiChar);
bool isUppercase(int asciiChar);

// Affine Cipher
void affine();
string affine_encrypt(string text, int shiftKey, int coprime);
string affine_decrypt(string text, int shiftKey, int coprime);
bool affine_isKeyValid(string key);
bool isCoprime(int key);

// Super Enkripsi
void super();

int main()
{
  // (123210078) Muhammad Rafli
  // (123210196) Nasywa Nadya Nur Hafizhah
  // Kriptografi
  // IF-H

  char pilih;

  cout << "Jenis Enkripsi: \n"
       << "[1] Caesar Cipher \n"
       << "[2] Vigenere Cipher \n"
       << "[3] Affine Cipher \n"
       << "[4] Super Enkripsi \n"
       << "[Lainnya] Keluar \n"
       << "Pilih > ";
  cin >> pilih;
  cout << endl;

  switch (pilih)
  {
  case '1':
    caesar();
    cout << endl;
    break;

  case '2':
    vigenere();
    cout << endl;
    break;
  case '3':
    affine();
    cout << endl;
    break;
  case '4':
    super();
    cout << endl;
    break;

  default:
    break;
  }

  return 0;
}

void caesar()
{
  string text, key;

  cout << "Caesar Cipher \n";
  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, text);
  cout << "Masukkan key: ";
  getline(cin, key);
  cout << endl;

  if (caesar_isKeyValid(key))
  {
    int validKey = stoi(key);
    string encrypted_text = caesar_encrypt(text, validKey);
    string decrypted_text = caesar_decrypt(encrypted_text, validKey);

    cout << "Cipher Text: \n"
         << encrypted_text << "\n\n";
    cout << "Plain Text: \n"
         << decrypted_text << "\n";
  }
  else
  {
    cout << "Key tidak valid." << endl;
  }
}

void vigenere()
{
  string text, cipherText, plainText;
  string keyword, key;

  cout << "Vigenere Cipher \n";
  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, text);
  cout << "Masukkan kata kunci: ";
  getline(cin, keyword);
  cout << endl;

  if (vigenere_isKeyValid(keyword))
  {
    key = vigenere_generate_key(text, keyword);
    cipherText = vigenere_encrypt(text, key);
    plainText = vigenere_decrypt(cipherText, key);

    cout << "Cipher Text: \n"
         << cipherText << "\n\n";

    cout << "Plain Text: \n"
         << plainText << "\n";
  }
  else
    cout << "Key tidak valid. \n";
}

void affine()
{
  bool isShiftKeyNum, isCoprimeNum;
  string inputText, inputCoprime, inputShiftKey;

  cout << "Affine Cipher \n";
  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, inputText);
  cout << "Masukkan jumlah pergeseran: ";
  getline(cin, inputShiftKey);
  cout << "Masukkan bilangan yg relatif prima dengan 26: ";
  getline(cin, inputCoprime);
  cout << endl;

  isShiftKeyNum = affine_isKeyValid(inputShiftKey);
  isCoprimeNum = affine_isKeyValid(inputCoprime);

  if (isShiftKeyNum && isCoprimeNum)
  {
    if (isCoprime(stoi(inputCoprime)))
    {
      int shiftKey = stoi(inputShiftKey);
      int coprime = stoi(inputCoprime);
      string cipherText = affine_encrypt(inputText, shiftKey, coprime);
      string plainText = affine_decrypt(inputText, shiftKey, coprime);

      cout << "Cipher Text: \n"
           << cipherText << "\n\n";
      cout << "Plain Text: \n"
           << plainText << "\n";
    }
    else
      cout << "Bilangan " << inputCoprime << " tidak relatif prima dengan 26";
  }
  else
    cout << "Kunci tidak valid";
}

void super()
{
  bool isAllkeyValid;
  string caesar_inputKey, affine_inputShiftKey, affine_inputCoprime;
  string inputText;
  string vigenere_inputKeyword;

  cout << "Super Cipher (Caesar + Vigenere + Affine) \n";
  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, inputText);

  cout << "Caesar: \n";
  cout << "Masukkan key: ";
  getline(cin, caesar_inputKey);
  cout << endl;

  cout << "Vigenere: \n";
  cout << "Masukkan keyword: ";
  getline(cin, vigenere_inputKeyword);
  cout << endl;

  cout << "Affine: \n";
  cout << "Masukkan jumlah pergeseran: ";
  getline(cin, affine_inputShiftKey);
  cout << "Masukkan bilangan yg relatif prima dengan 26: ";
  getline(cin, affine_inputCoprime);
  cout << endl;

  isAllkeyValid =
      caesar_isKeyValid(caesar_inputKey) &&
      vigenere_isKeyValid(vigenere_inputKeyword) &&
      affine_isKeyValid(affine_inputShiftKey) &&
      affine_isKeyValid(affine_inputCoprime);

  // Ngecek key valid apa engga
  if (isAllkeyValid)
  {
    if (isCoprime(stoi(affine_inputCoprime)))
    {
      int caesar_key = stoi(caesar_inputKey);
      int affine_shifKKey = stoi(affine_inputShiftKey);
      int affine_coprime = stoi(affine_inputCoprime);
      string vigenere_keyword = vigenere_generate_key(inputText, vigenere_inputKeyword);

      // Proses enkripsi dengan algoritma super enkripsi
      string caesar_cipherText = caesar_encrypt(inputText, caesar_key);
      string vigenere_cipherText = vigenere_encrypt(caesar_cipherText, vigenere_keyword);
      string affine_cipherText = affine_encrypt(vigenere_cipherText, affine_shifKKey, affine_coprime);

      // Proses dekripsi
      string affine_plainText = affine_decrypt(affine_cipherText, affine_shifKKey, affine_coprime);
      string vigenere_plainText = vigenere_decrypt(affine_plainText, vigenere_keyword);
      string caesar_plainText = caesar_decrypt(vigenere_plainText, caesar_key);

      // Menampilkan hasil
      cout << "Cipher Text: \n"
           << affine_cipherText << "\n\n";

      cout << "Plain Text: \n"
           << caesar_plainText << "\n";
    }
    else
      cout << "Bilangan " << affine_inputCoprime << " tidak relatif prima dengan 26";
  }
  else
    cout << "Key tidak valid." << endl;
}

// CAESAR CIPHER
string caesar_encrypt(string text, int key)
{
  string encrypted_text = "";
  for (char &c : text)
  {
    if (isalpha(c))
    {
      char base = (islower(c)) ? 'a' : 'A';
      int standarized_c = c - base; // Distandarisasi dulu dari ASCII jadi alphabet

      key = key < 0 ? ((key % 26) + 26) % 26 : key; // ngecek key-nya minus apa ga

      int result = (standarized_c + key) % 26; // lakuin operasi caesar cipher
      c = result + base;                       // Ubah dari alphabet ke ASCII
    }
    encrypted_text += c; // huruf hasil enkripsi di push nyampe bentuk teks
  }
  return encrypted_text;
}

string caesar_decrypt(string text, int key)
{
  key %= 26;
  return caesar_encrypt(text, 26 - key); // Decrypting is just encrypting with the reverse shift
}

// buat ngecek key valid apa engga
bool caesar_isKeyValid(string key)
{
  bool isValid = true;
  // ngecek digit pertama 0 apa engga
  if (key.size() > 1 && ((int)key[0] == 48 || (int)key[0] == 45))
    isValid = false;

  // ngecek key huruf apa engga
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

// AFFINE CIPHER
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

      shiftKey = shiftKey < 0 ? ((shiftKey % 26) + 26) % 26 : shiftKey; // ngecek key-nya minus apa ga
      int result = (coprime * standarized_huruf + shiftKey) % 26;       // operasi affine cipher
      text[i] = result + base;                                          // ubah dari alphabet ke ASCII
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
bool affine_isKeyValid(string key)
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

// VIGENERE CIPHER
string vigenere_generate_key(string text, string keyword)
{
  string key;
  int i = 0, j = 0;

  // Looping sampe plainteksnya abis
  while (key.size() != text.size())
  {
    // kalo key-nya udah abis, diulangin lagi dari awal
    if (i == keyword.size())
      i = 0;

    // kalo plainteks-nya huruf, masukkin key-nya
    if (isalpha(text[j]))
    {
      key.push_back(keyword[i]);
      i++;
    }
    // kalo bukan, key-nya diconvert ke spasi
    else
      key.push_back(' ');
    j++;
  }
  return key;
}

bool vigenere_isKeyValid(string keyword)
{
  bool isValid = true;
  // Buat ngecek key valid atau engga
  for (int i = 0; i < keyword.size(); i++)
  {
    if (!isalpha(keyword[i]))
    {
      isValid = false;
      break;
    }
  }
  return isValid;
}

// buat ngecek uppercase atau bukan
bool isUppercase(int asciiChar)
{
  return asciiChar >= 65 && asciiChar <= 90;
}

// buat ngecek lowercase atau bukan
bool isLowercase(int asciiChar)
{
  return asciiChar >= 97 && asciiChar <= 122;
}

string vigenere_encrypt(string text, string key)
{
  int asciiText, asciiKey;
  string cipherText;

  for (int i = 0; i < text.size(); i++)
  {
    if (isalpha(text[i]))
    {
      // Huruf di plainteks sama key dikonversi ke ASCII
      int textInAscii = (int)text[i];
      int keyInAscii = (int)key[i];

      // kalo plainteks lowercase
      if (isLowercase(textInAscii))
        asciiText = 97;
      // kalo plainteks uppercase
      else if (isUppercase(textInAscii))
        asciiText = 65;

      // kalo key lowercase
      if (isLowercase(keyInAscii))
        asciiKey = 97;
      // kalo key uppercase
      else if (isUppercase(keyInAscii))
        asciiKey = 65;

      // nyetarain antara uppercase sama lowercase di plainteks dan key
      textInAscii -= asciiText;
      keyInAscii -= asciiKey;

      int x = (textInAscii + keyInAscii) % 26;
      x += asciiText;
      cipherText.push_back((char)x);
    }
    else
      cipherText.push_back(text[i]);
  }
  return cipherText;
}

string vigenere_decrypt(string cipherText, string key)
{
  int asciiText, asciiKey;
  string plainText;

  for (int i = 0; i < cipherText.size(); i++)
  {
    if (isalpha(cipherText[i]))
    {
      int textInAscii = (int)cipherText[i];
      int keyInAscii = (int)key[i];

      if (isUppercase(textInAscii) || isLowercase(textInAscii))
      {
        if (isLowercase(textInAscii))
          asciiText = 97;
        else if (isUppercase(textInAscii))
          asciiText = 65;

        if (isLowercase(keyInAscii))
          asciiKey = 97;
        else if (isUppercase(keyInAscii))
          asciiKey = 65;

        textInAscii -= asciiText;
        keyInAscii -= asciiKey;

        int x = (textInAscii - keyInAscii + 26) % 26;
        x += asciiText;
        plainText.push_back((char)x);
      }
      else
        plainText.push_back(plainText[i]);
    }
    else
      plainText.push_back(cipherText[i]);
  }

  return plainText;
}