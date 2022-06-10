#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{	
	int event = 0;
	int st_hh, et_hh, st_mm, et_mm = 0;
	int hour = 0,min=0,main=0,counter=0;
	int a, b, c = 0;
	char op;
	bool conflict[24][60]{ false };
	cout << "start";
	cin >> st_hh >> op >> st_mm;
	cout << "end";
	cin >> et_hh >> op >> et_mm;
	hour = et_hh - st_hh;
	min = et_mm - st_mm;
	counter = min + (hour*60);
	a = st_hh;
	b = st_mm;
	event = 2;
	for (int x = 1;x = event;x++)
	{
		// new st_hh,st_mm here
		a = /*record[]*/st_hh;
		b = st_mm;
		for (int i = 1;i <= counter;i++)
		{
			conflict[a][b] = true;
			b = b + 1;
			if (b > 59)
			{
				a = a + 1;
				b = 0;
			}
		}
	}
	return 0;
}

