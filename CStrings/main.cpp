#include<iostream>
#include<Windows.h>
#include<ctype.h>

using namespace std;

int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);
int Power(int a, int n);

bool is_int_number(char str[]);
int  to_int_number(char str[]);
bool is_bin_number(char str[]);
int  bin_to_dec(char str[]);
bool is_hex_number(char str[]);
int  hex_to_dec(char str[]);



//#define BASE_STRINGS_OPERATIONS
//#define BINARY_NUMBERS

void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("CLS");

	const int n = 256;
	char str[n];

	cout << "Введите строку: "; cin.getline(str, n);


#ifdef BASE_STRINGS_OPERATIONS
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

	//proverka(str);

	cout << (is_palindrome(str) ? "Yes" : "No") << endl;

	cout << (is_int_number(str) ? "Число" : "Не число") << endl;
	cout << to_int_number(str) << endl;

#endif // BASE_STRINGS_OPERATIONS

	
#ifdef BINARY_NUMBERS
	cout << "Строка " << (is_bin_number(str) ? "двоичная" : "не двоичная") << endl;
	cout << "Значение двоичного числа: ";
	cout << bin_to_dec(str) << endl;
#endif // BINARY_NUMBERS


	cout << "Строка " << (is_hex_number(str) ? "шестнадцатеричная" : "не шестнадцатеричная") << endl;
	cout << "Значение шестнадцатеричного числа: " << endl;;
	cout << hex_to_dec(str) << endl;
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

//bool is_palindrome(char str[])
//{
//	//to_lower(str);
//	for (int i = 0; str[i]; i++)
//	{
//		if (str[i] == ' ')
//		{
//			for (int j = i; str[j]; j++)
//			{
//				str[j] = str[j + 1];
//			}
//			i--;
//		}
//
//	}
//	int a = 0;
//	int b = 0;
//	for (int i = 0; str[i]; i++)
//	{
//		a += (int)str[i];
//	}
//	int buffer = a;
//	while (buffer)
//	{
//		b *= 10;
//		b += buffer % 10;
//		buffer /= 10;
//	}
//	
//	if (a!=0 && a == b)
//	{
//		cout << "это палиндром" << endl;
//		return true;
//	}
//	else if (a != b)
//	{
//		cout << "это не палиндром" << endl;
//		return false;
//	}
//    
//}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}

	}
}

bool is_palindrome(char str[])
{
	//определяем длину строки
	int size = StrLen(str);
	char* buffer = new char[size + 1] {};
	//for (int i = 0; str[i]; i++)buffer[i] = str[i];
	strcpy(buffer, str); // String Copy. 
	                     // buffer - строка получатель
						 // str - строка источник
					   
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	size = strlen(buffer);

	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	/*for (int i = 0; str[i]; i++)
	{
		for (int j = 0; str[j]; j++)
		{
			if (str[j] < '0' || str[j]>'9' || str[i]!=' ')
			{
				return false;
			}
		}
		return true;
	}*/

	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9')&& str[i]!=' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int number = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')continue;
		number *= 10;  //сдвигаем число на разряд влево(освобождаем млад разряд)
		number += str[i] - 48;

	}
	return number;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int bin_to_dec(char str[])
{
	//if (!is_bin_number(str))return 0;
	////remove_symbol(str, ' ');
	//int decimal = 0;
	//int a = 2;
	//int n = strlen(str);
	////int weight = 0; // весовой коэффициент разряда 
	//
	//for (int i = 0; str[i]; i++)
	//{	
	//	if (str[i] == ' ')continue;
	//	for (int j = n - 1; j >= 0; j--)
	//	{
	//		decimal += (str[i]-48) * Power(a, j);
	//		
	//	}
	//	
	//}
	//
	//return decimal;

	//remove_symbol(str, ' ');
	if (!is_bin_number(str))return 0;
	int decimal = 0;	  // Конечное десятичное число
	int n = StrLen(str);  // Разрядность числа
	int weight = 1;       // Весовой коэффицент разряда
	for (int i = n-1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	
	}
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') && 
			!(str[i] >= 'A' && str[i] <= 'F') && 
			!(str[i] >= 'a' && str[i] <= 'f') && 
			str[i] != ' '
			)
			return false;

		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int  hex_to_dec(char str[])
{
	if (!is_hex_number(str))return 0;
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	strcpy(buffer, str);
	to_upper(buffer);

	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i > 0; i--)
	{
		if (buffer[i] == 'X')break;
		if (buffer[i] != ' ')
		{
			/*if (str[i] >= '0' && str[i] <= '9')
			{
				decimal += (str[i] - 48) * weight;
				weight *= 16;
			}
			else if (str[i] >= 'A' && str[i] <= 'F')
			{
				decimal += (str[i] - 55) * weight;
				weight *= 16;
			}
			else if (str[i] >= 'a' && str[i] <= 'f')
			{
				decimal += (str[i] - 87) * weight;
				weight *= 16;
			}*/
			decimal += (buffer[i] - (isdigit(buffer[i]) ? 48 : 55)) * weight;
			weight *= 16;

		}
	}
	return decimal;
}

int Power(int a, int n)
{
	int save = 0;
	save = a;
	for (int i = 1; i < n; i++)
	{
		a *= save;
	}
	return a;
}

