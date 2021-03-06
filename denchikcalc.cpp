// калькулятор имени денчика в польской нотации
#include "stdafx.h"
#include <iostream>
using namespace std;

float number()
{
	int res = 0;
	for (;;)
	{
		char c = cin.get();
		if (c >= '0' and c <= '9') res = res * 10 + c - '0';
		else
		{
			cin.putback(c);
			return res;
		}
	}
}

float factor()
{
	float n = number();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '*':
			return n * number();
		case '/':
			return n / number();
		default:
			cin.putback(c);
			return n;
		}
	}
}

float expr()
{
	float n = factor();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '+':
			return n + factor();
		case '-':
			return n - factor();
		default:
			cin.putback(c);
			return n;
		}
	}
}

int main()
{
	//setlocale(LC_ALL, "rus");
	cout << "Enter expression" << endl;
	cout << expr() << endl;
	system("pause");
    return 0;
}

