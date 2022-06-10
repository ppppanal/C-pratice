#include <iomanip>
#include <iostream>
#include <clibstd>
#include <string>
using namespace std;
int p()
{
	int total=0;
	int write[20];
	cout << "How many integers to enter? "
	cin >> total;
	for (int a = 0;a < total;a++)
	{
		cout << "?";
		cin >> write[a];
	}
	cout << "The bar chart is: ";
	for (int i = 0;i < total;i++)
	{
		for (int j = 0; j < write[i];j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}