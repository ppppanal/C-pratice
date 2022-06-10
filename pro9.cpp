// SEHH2042 Additional Assignment
// Program template file

// Insert more header files when necessary
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

void showInfo()
{
	cout << "Name : Law Chun Ho" << endl;
	cout << "Class : 204" << endl;
	cout << "StudentID : 191364252A" << endl;
}

void Q1()
{
	string byt[5] = { "" };
	int key = 0;
	double val = 0;
	byt[0] = "B";
	byt[1] = "KB";
	byt[2] = "MB";
	byt[3] = "GB";
	byt[4] = "TB";
	cin >> val;
	while (val >= 1024)
	{
		val = val / 1024;
		key = key + 1;
	}
	cout <<fixed<< setprecision(2) << val << byt[key];
}

void Q2()
{
	int a, b, c,size = 0;
	int counter = 0;
	cin >> size;
	a = (size + 1) / 2;
	b = (size - 1) / 2;
	c = size-2;
	for (int i = 0;i <= b;i++)
	{
		cout << "|" << setw(size+1)<<"|"<<endl;
	}
	cout << "|";
	for (int j = 1;j <= size;j++)
	{
		cout << "*";
	}
	cout << "|" << endl;	
	while(c>=3)
	{
		counter++;
		cout << setw(counter+1)<<'\\';
		for (int p = 0;p < c;p++)
		{
			cout << "*";
		}
		cout << '/' << setw(counter) << endl;
		c=c-2;
	}
	cout << setw(counter+2) << '-'<<'-'<<'-'<< endl;
	counter++;
	for (int q = 0;q <= b;q++)
	{
		cout << setw(counter+2) << '|' << setw(counter+2)<<endl;
	}
	cout << setw(counter+1) << '-' <<'-'<<'-' << endl;
}

// Insert your function for Q3() here
int counting(int n, int k )
{
	int a = 0;
	int b = 0;
	string fn = to_string(n);
	string sn = to_string(k);
	int counter = 0;
	fn = to_string(n);
	sn = to_string(k);
	a = fn.length();
	b = sn.length();
	for (int i = 0;i < a;i++)
	{
		bool repeat = true;
		if (fn[i] == sn[0])
		{
			for (int j=0;j<b;j++)
			{				
				if (fn[i+j] != sn[j])
				{
					repeat = false;		
					break;
				}
			}
			if (repeat == true)
			{
				counter++;
			}
		}		
	}
	cout<<counter<<endl;
	int num = 0;
	cin >> num;
	string m = to_string(num);
	int repeated[10] = { 0 };
	int d = 0;
	int most = 0;
	d = m.length();
	for (int p = 0;p <= d;p++)
	{
		for (int q = 0;q <= 9;q++)
		{
			if (q+1 == (int(m[p])-47))
			{
				repeated[q]++;
			}
		}
	}
	for (int r = 0;r <= 9;r++)
	{
		for (int s = 0;s <= 9;s++)
		{
			if ((repeated[s] >= repeated[r])&&(repeated[s] >= repeated[most]))
			{
				if (s > r)
				{
					most = s;
				}
			}
		}		
	}
	return most;
}
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

class RightTriangle 
{ 
private: 
int ID = 0;
double a = 0.0;
double b = 0.0;
double hypo(double a, double b)
{
	return sqrt(a * a + b * b);
}
public:
void setSides(double num2, double num3)
{
	a = num2;
	b = num3;
}
void display()
{
	cout << ID << ":" << a << "/" << b << "/" << hypo(a, b) << "/" << (atan(b/a)*(180/3.14159265)) << endl;
}
RightTriangle(int num)
{
	ID = num;
}


};

void Q4()
{
	// IMPORTANT:
	// Remove the given code below if you DON'T attempt this question
	// Otherwise, you will have syntax error

	//GIVEN CODES, DO NOT MODIFY 
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
	int n = 0;
	int t = 0;
	int count = 0;
	int min = 0;
	cin >> n;
	cin >> t;
	int mark[1000][50] = { 0 };
	int res[1000] = { 0 };
	bool beaten[1000]{ false };
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < t; j++) 
		{
			cin >> mark[i][j];
		}
	}
	for (int stua = 0; stua < n; stua++) 
	{
		for (int stub = 0; stub < n; stub++) 
		{
			if (stua != stub) 
			{
				int leq = 0;
				int lg = 0;
				for (int k = 0; k < t; k++) 
				{
					if (mark[stua][k] >= mark[stub][k]) 
					{
						leq++;
					}
					if (mark[stua][k] > mark[stub][k]) 
					{
						lg++;
					}
					if (leq == t && lg > 0) {
						beaten[stub] = true;
					}
				}
			}
		}
	}
	for (int ac = 0;ac < n;ac++)
	{
		if (beaten[ac] == false)
		{
			res[ac] = mark[ac][0];
			count++;
		}
	}
	min = 2147483647;
	for (int z = 0;z < n;z++)
	{
		if (res[z] < min && (res[z] != 0))
		{
			min = res[z];
		}
	}
	cout << count << endl;
	cout << min << endl;
}

// Insert your class and function (if any) for Q6() here
class student
{public:
	string course;
	string sid;
	double mark;
};
student stu[1000];
student result[1000];
student sp;
void Q6()
{
	string course;
	string sid;
	double mark;
	string search;
	int count = 0;
	int count2 = 0;
	double mavg = 0;

	while (course != "END")
	{
		cin >> course;
		if (course == "END")
		{
			break;
		}
		cin >> sid;
		cin	>> mark;
		stu[count].course = course;
		stu[count].sid = sid;
		stu[count].mark = mark;
		count++;
	}
	cin >> search;
	for (int i = 0;i < count;i++) 
	{
		if (stu[i].course == search)
		{
			result[count2].sid = stu[i].sid;
			result[count2].course = stu[i].course;
			result[count2].mark = stu[i].mark;
			count2++;
		}
	}
	for (int j = 0;j < count2;j++) 
	{
		for (int k = 0;k < count2;k++)
		{
			if (result[j].sid<result[k].sid)
			{
				sp = result[k];
				result[k] = result[j];
				result[j] = sp;
			}			
		}
	}
	for (int p = 0;p < count2;p++) 
	{
		cout << result[p].sid << " " << result[p].mark << endl;
	}
	for (int q = 0;q <= count2;q++) 
	{
		mavg = mavg + result[q].mark;
	}
	mavg = mavg / (count2);
	if (count2 != 0) 
	{
		cout << "Average: " << fixed << setprecision(1) << mavg<<endl;
		cout << "Maximum: " << fixed << setprecision(1) << result[0].mark<<endl;
		cout << "Minimum: " << fixed << setprecision(1) << result[count2-1].mark<<endl;
	}
	else
	{
		cout << "No such record" << endl;
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