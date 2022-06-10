// SEHH2042 Assignment 1
// Program template file: A1Template.cpp

// Insert more header files when necessary
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void showInfo()
{
	cout << "Name       : Law Chun Ho" << endl;
	cout << "Student ID : 19136425A" << endl;
	cout << "Class      : 202A";
}

void Q1()
{
	cout << "Use \"text\" to display string content";


}

void Q2()
{
	string item;
	string item2; 
	double price, price2;
	cin >> item >> price;
	cin >> item2 >> price2;
	cout<< fixed << left << setw(10) << item << "$" << setprecision(2) << price << endl;
	cout<< fixed << left <<setw(10) << item2 << "$" << setprecision(2) << price2;

	
	
}

void Q3()
{
	double num1=0, num2=0, num3=0, ans=0;
	char op1, op2;
	cin >> num1 >> op1 >> num2 >> op2 >> num3;
	if (((op2 == 'x') ||(op2 == '/')) && ((op1 == '+') || (op1 == '-')))
	{
		switch (op2)
		{
		case 'x':ans = num2 * num3;
			break;
		case '/':ans = num2 / num3;
			break;
		}
		switch (op1)
		{
		case '+': cout << ans + num1;
			break;
		case '-': cout << ans - num1;
			break;
		}
	}
	else 
	{
		switch (op1)
		{
		case 'x':ans = num1 * num2;
			break;
		case '/':ans = num1 / num2;
			break;
		case '+':ans = num1 + num2;
			break;
		case '-':ans = num1 / num2;
			break;
		}
		switch (op2)
		{
		case '+': cout << ans + num3;
			break;
		case '-': cout << ans - num3;
			break;
		case 'x': cout << ans * num3;
			break;
		case '/': cout << ans / num3;
			break;
		}
	}
}
	


void Q4()
{
	int count=0, input=0;
	cin >> input;
	while (input != 0)
	{ 
		if ((input < -999) && (input > -9999) && (input %2 == 0))
		{
			count = count + 1;
		
		}
		cin >> input;
	}
	cout << count; 
}



void Q5()

{
	int in, a, b = 0;
	int main();
	cin >> in;
	a = (in * 2) - 1;
	b = ((a - 1) / 2) + 1;
	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= in * 2; j++)
		{
			if ((i == 2) || (i == 1))
			{
				if ((j > (b - i)) && (j <= in))
					cout << '*';
				else
					cout << ' ';
			}
			else
			{
				if ((j > (b - i)))
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << endl;
	}

	for (int i = b + 1; i <= a; i++)
	{
		for (int j = 1; j <= in * 2; j++)
		{
			if ((i == a) || (i == a - 1))
			{
				if ((j > (i - b)) && (j <= in))
					cout << '*';
				else
					cout << ' ';
			}
			else
			{
				if ((j > (i - b)))
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << endl;
	}
}

// GIVEN CODES, DO NOT MODIFY 
// BEGIN
int main()
{
	char prog_choice;

	do {
		cout << "\n\n";
		cout << "Program Selection Menu" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Enter question number ('q' to quit): ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
		case '0': showInfo(); break;
		case '1': Q1(); break;
		case '2': Q2(); break;
		case '3': Q3(); break;
		case '4': Q4(); break;
		case '5': Q5(); break;
		case 'q': break;
		default:
			cout << "No such question " << prog_choice << endl;
			break;
		}
	} while (prog_choice != 'q');

	cout << "Program terminates. Good bye!" << endl;
	return 0;
}
// END