#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int midSquare(string data);

int main()
{
  cout << midSquare("Rafli");

  return 0;
}

int midSquare(string data)
{
  int sum = 0, sumLength = 0;
  string num;
  string sumStr;

  for (int i = 0; i < data.length(); i++)
    sum += int(data[i]);

  sum *= sum;
  sumStr = to_string(sum);
  sumLength = sumStr.length();

  cout << data << " = " << sum << " = ";

  if (sumLength % 2 == 0)
  {
    char firstNum = sumStr[sumLength / 2 - 1];
    char secondNum = sumStr[sumLength / 2];
    num = {firstNum, secondNum};
  }
  else if (sumLength % 2 != 0 && sumLength > 1)
  {
    char firstNum = sumStr[sumLength / 2 - 1];
    char secondNum = sumStr[sumLength / 2];
    num = {firstNum, secondNum};
  }
  else
    num = {sumStr[sumLength / 2 - 1]};

  return stoi(num);
}