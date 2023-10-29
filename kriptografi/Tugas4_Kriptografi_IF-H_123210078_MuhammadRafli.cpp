#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Caesar Cipher
void caesar();
string caesar_decrypt(string text, int key);
string caesar_encrypt(string text, int key);
bool isKeyValid(string key);

// Rail Fence Cipher
void railFence();
string rail_fence_decrypt(const string &ciphertext, int rails);
string rail_fence_encrypt(const string &plaintext, int rails);

// Vigenere Cipher
void vigenere();
string vigenere_generate_key(string text, string keyword);
string vigenere_encrypt(string text, string key);
string vigenere_decrypt(string cipherText, string key);
bool isLowercase(int asciiChar);
bool isUppercase(int asciiChar);

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
       << "[3] Rail Fence Cipher \n"
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
    railFence();
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
  bool isValid;
  string text, key;

  cout << "Caesar Cipher \n";
  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, text);
  cout << "Masukkan key: ";
  getline(cin, key);
  cout << endl;

  isValid = isKeyValid(key);
  if (isValid)
  {
    int validKey = stoi(key);
    string encrypted_text = caesar_encrypt(text, validKey);
    string decrypted_text = caesar_decrypt(encrypted_text, validKey);

    cout << "Cipher Text dari \"" << text << "\": "
         << encrypted_text << "\n\n";
    cout << "Plain Text dari  \"" << encrypted_text << "\": "
         << decrypted_text << "\n";
  }
  else
  {
    cout << "Key tidak valid." << endl;
  }
}

void railFence()
{
  int choice, rails;
  string text;

  cout << "Rail Fence Cipher \n"
       << "1: Enkripsi, 2: Dekripsi, 0: Keluar \n"
       << "Pilih Menu > ";
  cin >> choice;

  switch (choice)
  {
  case 0:
    break;
  case 1:
  {
    cout << "Masukkan teks yang akan dienkripsi: ";
    cin.ignore();
    getline(cin, text);
    cout << "Masukkan jumlah rail: ";
    cin >> rails;

    string encrypted_text = rail_fence_encrypt(text, rails);
    cout << "Teks yang dienkripsi: " << encrypted_text << endl;
    break;
  }
  case 2:
  {
    cout << "Masukkan teks yang akan didekripsi: ";
    cin.ignore();
    getline(cin, text);
    cout << "Masukkan jumlah rail: ";
    cin >> rails;

    string decrypted_text = rail_fence_decrypt(text, rails);
    cout << "Teks yang didekripsi: " << decrypted_text << endl;
    break;
  }
  default:
    cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 0." << endl;
    break;
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

  key = vigenere_generate_key(text, keyword);

  if (key != "-1")
  {
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

void super()
{
  int caesarKey, railfenceRails;
  string text;
  string vigenereKeyword, vigenereKey;
  string caesarCipherText, railfenceCipherText, vigenreCipherText;
  string caesarPlainText, railfencePlainText, vigenerePlainText;

  cout << "Super Cipher (Caesar + Rail Fence + Vigenere) \n";
  cout << "Masukkan teks: ";
  cin.ignore();
  getline(cin, text);
  cout << "Masukkan kunci untuk caesar: ";
  cin >> caesarKey;
  cout << "Masukkan jumlah rail: ";
  cin >> railfenceRails;
  cout << "Masukkan kata kunci untuk vigenere: ";
  cin >> vigenereKeyword;
  cout << endl;

  // Proses enkripsi
  caesarCipherText = caesar_encrypt(text, caesarKey);
  railfenceCipherText = rail_fence_encrypt(caesarCipherText, railfenceRails);
  vigenereKey = vigenere_generate_key(railfenceCipherText, vigenereKeyword);
  vigenreCipherText = vigenere_encrypt(railfenceCipherText, vigenereKey);

  // Proses dekripsi
  vigenerePlainText = vigenere_decrypt(vigenreCipherText, vigenereKey);
  railfencePlainText = rail_fence_decrypt(vigenerePlainText, railfenceRails);
  caesarPlainText = caesar_decrypt(railfencePlainText, caesarKey);

  cout << "Cipher Text dari \"" << text << "\": "
       << vigenreCipherText << endl;
  cout << "Plain Text dari \"" << vigenreCipherText << "\" : "
       << caesarPlainText << endl;
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
bool isKeyValid(string key)
{
  bool isValid = true;
  // ngecek key valid apa engga
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

// RAIL FENCE CIPHER
string rail_fence_encrypt(const string &plaintext, int rails)
{
  vector<string> fence(rails);
  int rail = 0;
  bool down = false;

  for (char c : plaintext)
  {
    fence[rail] += c;

    if (rail == 0 || rail == rails - 1)
    {
      down = !down;
    }

    rail += down ? 1 : -1;
  }

  string encrypted_text;
  for (const string &rail_text : fence)
  {
    encrypted_text += rail_text;
  }

  return encrypted_text;
}

string rail_fence_decrypt(const string &ciphertext, int rails)
{
  vector<string> fence(rails);
  vector<int> rail_lengths(rails, 0);

  int rail = 0;
  bool down = false;

  for (size_t i = 0; i < ciphertext.length(); i++)
  {
    rail_lengths[rail]++;

    if (rail == 0 || rail == rails - 1)
    {
      down = !down;
    }

    rail += down ? 1 : -1;
  }

  int pos = 0;
  for (int i = 0; i < rails; i++)
  {
    fence[i] = ciphertext.substr(pos, rail_lengths[i]);
    pos += rail_lengths[i];
  }

  string decrypted_text;
  rail = 0;
  down = false;

  for (size_t i = 0; i < ciphertext.length(); i++)
  {
    decrypted_text += fence[rail][0];
    fence[rail].erase(0, 1);

    if (rail == 0 || rail == rails - 1)
    {
      down = !down;
    }

    rail += down ? 1 : -1;
  }

  return decrypted_text;
}

// VIGENERE CIPHER
string vigenere_generate_key(string text, string keyword)
{
  bool isValid = true;
  string key;
  int textLength = text.size();
  int i = 0, j = 0;

  // Buat ngecek valid atau engga
  for (i = 0; i < keyword.size(); i++)
  {
    if (!isalpha(keyword[i]))
    {
      isValid = false;
      break;
    }
  }
  if (!isValid)
    return "-1";

  // Looping sampe plainteksnya abis
  while (key.size() != textLength)
  {
    // kalo keynya udah abis, diulangin lagi dari awal
    if (i == keyword.size())
      i = 0;

    // kalo plainteks-nya huruf, masukkin keynya
    if (isalpha(text[j]))
    {
      key.push_back(keyword[i]);
      i++;
    }
    // kalo bukan, keynya diconvert ke spasi
    else
      key.push_back(' ');
    j++;
  }
  return key;
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