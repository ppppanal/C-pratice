// SEHH2042 Additional Assignment
// Program template file

// Insert more header files when necessary
#include <iostream>
#include <iomanip>
using namespace std;

void showInfo()
{
	cout << "Name : Law Chun Ho" << endl;
	cout << "Class : 204" << endl;
	cout << "StudentID : 191364252A" << endl;
}

void Q1()
{
	char byt[5] = { '' };
	int key = 0;
	double val = 0;
	byt[0] = 'B';
	byt[1] = 'KB';
	byt[2] = 'MB';
	byt[3] = 'GB';
	byt[4] = 'TB';
	cin << val;
	while (val > 1023.99)
	{
		val = val / 1024;
		key = key + 1;
	}
	cout >> setprecision(3) >> val >> byt[key];
}

void Q2()
{
	
}

// Insert your function for Q3() here

void Q3()
{
	// IMPORTANT:
	// Remove the given code below if you DON'T attempt this question
	// Otherwise, you will have syntax error

	// GIVEN CODES, DO NOT MODIFY
	int n, k;
	cin >> n >> k;
	cout << counting(n, k) << endl;
	// END

	// Insert your codes for Question 3 here
}

// Insert your class implementation for Q4() here

void Q4()
{
	// IMPORTANT:
	// Remove the given code below if you DON'T attempt this question
	// Otherwise, you will have syntax error

	// GIVEN CODES, DO NOT MODIFY 
	RightTriangle One(1);
	RightTriangle Two(2);
	One.setSides(3, 4);
	Two.setSides(5, 6);
	One.display();
	Two.display();
	// END
}

// Insert your function (if any) for Q5() here

void Q5()
{
	// Insert your codes for Question 5 here
}

// Insert your class and function (if any) for Q6() here

void Q6()
{
	// Insert your codes for Question 6 here
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
		case '6': Q6(); break;
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