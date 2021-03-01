#include<iostream>
#include<Windows.h>
using namespace std;

int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("CLS");
	//char str[] = { 'H', 'e', 'l', 'l', 'o' , 0};
	//char str[] = "Hello";
	const int n = 20;
	char str[n];
	cout << "Введите строку: "; 
	//cin >> str;
	//SetConsoleCP(1251);
	cin.getline(str, n);
	//SetConsoleCP(866);

	//cout << str << endl;
	//cout << "Размер В байтах: "<<sizeof(str) << endl;
	//cout << "Размер в символах: " << StrLen(str) << endl;
	//ASCII();

	cout << "Строка в верхнем регистре: " << endl;
	to_upper(str);

	cout << "Строка в нижнем регистре: " << endl;
	to_lower(str);

	cout << "Строка c первыми заглавными буквами: " << endl;
	capitalize(str);

	cout << "Строка без лишних пробелов: " << endl;
	shrink(str);


}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{

	for (int i = 0; str[i]; i++)
	{
		//if (str[i] > 96 && str[i] < 123)str[i] -= 32;	
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;
		if (str[i] == 'ё')str[i] -= 16;
	}
	cout << str << endl;
	cout << endl;
}

void to_lower(char str[])
{
	
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;
		if (str[i] == 'Ё')str[i] += 16;
		
	}
	cout << str << endl;
	cout << endl;
}

void capitalize(char str[])
{	
	for (int i = 0; str[i]; i++)
	{	
		if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
		else if (str[0] == 'ё')str[0] -= 16;
		for (int i = 1; str[i]; i++)
		{
			if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i - 1] == ' ')str[i] -= 32;
			else if (str[i] == 'ё' && str[i - 1] == ' ')str[i] -= 16;
		}
		
	}
	
	cout << str << endl;
	cout << endl;
}

void shrink(char str[])
{
	for  (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i+1; str[j]; j++)	str[j] = str[j + 1];
			i--;
			
		}	
	}
	cout << str << endl;
	cout << endl;
}



