#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

const int MAXN = 105;
string url[MAXN];

int P = 0;
int len = 0;

void vis(string a)
{
	cout << a << endl;
	url[++P] = a;
	len = P;
}

void back()
{
	if (P == 0)
	{
		cout << "Ignored" << endl;
	}
	else if (P == 1)
	{
		cout << "http://www.acm.org/" << endl;
		P = 0;
	}
	else
	{
		cout << url[--P] << endl;
	}
}

void forward()
{
	if (++P > len)
	{
		cout << "Ignored" << endl;
		P = len;
	}
	else
	{
		cout << url[P] << endl;
	}
}

int main()
{
	string a;
	getline(cin, a);
	while (a != "QUIT")
	{
		if (a == "BACK")
			back();
		else if (a == "FORWARD")
			forward();
		else
			vis(a.substr(6));
		getline(cin, a);
	}
	return 0;
}
