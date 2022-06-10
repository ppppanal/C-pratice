#include <iomanip>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

void Q3()
{
	int tri(int d, int e, int f)
	{
		int total = 0;
		if (((d + e) > f) && ((d + f) > e) && ((e + f) > d) && (d != e) && (d != f) && (e != f)))
		{count = 1;}
	}
	int aaa()
	{
		int i = 0, a = 0, b = 0, c = 0;
		int group = 0;
		int line1 = 0;
		int line2 = 0;
		int line3 = 0;
		int run = 0;
		cin >> i;
		for (a = 1;a <= i - 2; a++)
		{
			line1 = 15 * (a * a) + 11 * a - 3;
			line2 = 15 * ((a + 1) * (a + 1)) + 11 * (a + 1) - 3;
			line3 = 15 * ((a + 2) * (a + 2)) + 11 * (a + 2) - 3;

			cout << a << "  " << b << "  " << c << endl;
			for (b = a + 1;b <= i - 1; b++)
			{
				line2 = 15 * (b * b) + 11 * (b)-3;
				line3 = 15 * ((b + 1) * (b + 1)) + 11 * (b + 1) - 3;
				cout << a << "  " << b << "  " << c << endl;
				for (c = a + 2;c <= i; c++)
				{
					line3 = 15 * ((c) * (c)) + 11 * (c)-3;
					cout << a << "  " << b << "  " << c << endl;
				}
			}
		}
		if (group > 0) { cout << line1 << "  " << line2 << "   " << line3 << endl; }
		cout << "group= " << group;
	}
}