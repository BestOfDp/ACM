#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	long long m, n, p;
	while (cin >> hex >> m >> n)
	{
		p = m + n;
		if (p < 0)
		{
			p = -p;
			cout << '-';
		}
		cout << setiosflags(ios::uppercase) << hex << p << endl;
	}
	return 0;
}
