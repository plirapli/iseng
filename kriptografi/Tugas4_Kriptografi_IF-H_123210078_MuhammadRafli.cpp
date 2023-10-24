#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Caesar Cipher
void caesar();
string caesar_decrypt(string text, int key);
string caesar_encrypt(string text, int key);

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
  bool repeat = 1;

  while (repeat)
  {
    cout << "Jenis Enkripsi: \n"
         << "[1] Caesar Cipher \n"
         << "[2] Rail Fence Cipher \n"
         << "[3] Vigenere Cipher \n"
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
      railFence();
      cout << endl;
      break;
    case '3':
      vigenere();
      cout << endl;
      break;
    case '4':
      super();
      cout << endl;
      break;

    default:
      repeat = 0;
      break;
    }
  }

  return 0;
}

void caesar()
{
  int choice, key;
  string text;

  cout << "Caesar Cipher \n"
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
    cout << "Masukkan key: ";
    cin >> key;

    string encrypted_text = caesar_encrypt(text, key);
    cout << "Teks yang dienkripsi: " << encrypted_text << endl;
    break;
  }
  case 2:
  {
    cout << "Masukkan teks yang akan didekripsi: ";
    cin.ignore();
    getline(cin, text);
    cout << "Masukkan key: ";
    cin >> key;

    string decrypted_text = caesar_decrypt(text, key);
    cout << "Teks yang didekripsi: " << decrypted_text << endl;
    break;
  }
  default:
    cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 0." << endl;
    break;
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
    cin.ignore(); // Clear the newline character from the buffer
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
    cin.ignore(); // Clear the newline character from the buffer
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
  cin >> keyword;
  cout << endl;

  key = vigenere_generate_key(text, keyword);
  cipherText = vigenere_encrypt(text, key);
  plainText = vigenere_decrypt(cipherText, key);

  cout << "Cipher Text dari \"" << text << "\": "
       << cipherText << endl;

  cout << "Plain Text dari \"" << cipherText << "\" : "
       << plainText << endl;
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

string caesar_encrypt(string text, int key)
{
  string encrypted_text = "";
  for (char &c : text)
  {
    if (isalpha(c))
    {
      char base = (islower(c)) ? 'a' : 'A';
      c = (c - base + key) % 26 + base;
    }
    encrypted_text += c;
  }
  return encrypted_text;
}

string caesar_decrypt(string text, int key)
{
  return caesar_encrypt(text, 26 - key); // Decrypting is just encrypting with the reverse shift
}

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

string vigenere_generate_key(string text, string keyword)
{
  string key;
  int textLength = text.size();
  int i = 0, j = 0;

  while (key.size() != textLength)
  {
    if (i == keyword.size())
      i = 0;

    if (text[j] != ' ')
    {
      key.push_back(keyword[i]);
      i++;
    }
    else
      key.push_back(' ');
    j++;
  }
  return key;
}

bool isUppercase(int asciiChar)
{
  return asciiChar >= 65 && asciiChar <= 90;
}

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
      int textInAscii = (int)text[i];
      int keyInAscii = (int)key[i];

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
    if (cipherText[i] != ' ')
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
      plainText.push_back(' ');
  }

  return plainText;
}