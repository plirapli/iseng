#include <iostream>
#include <string>

using namespace std;

int sumin(string str);

int main()
{
	string input;

	cout << "Input > ";
	getline(cin, input);

	cout << sumin(input);

	return 0;
}

int sumin(string str)
{
	int num[20], op[20];
	int jmlN = 0, jmlOp = 0;

	for (int i = 0; i < str.length(); i++)
	{
		int n = int(str[i]) - 48;

		if (n >= 0 && n < 10)
		{
			num[jmlN] = n;
			jmlN++;
		}

		else if (str[i] == '+' || str[i] == '-')
		{
			op[jmlOp] = str[i];
			jmlOp++;
		}
	}

	int sum = num[0];

	for (int i = 0; i < jmlOp; i++)
	{
		if (op[i] == '+')
			sum += num[i + 1];
		else
			sum -= num[i + 1];
	}

	return sum;
}