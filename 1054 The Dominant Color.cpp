#include<iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int a = 0, b = -1, c = 1;
	for (int i = 0; i < m*n; i++) {
		cin >> a;
		if (a == b)
			c++;
		else if(c==1)
		{
			b = a;
		}
		else
		{
			c--;
		}
	}
	cout << b;
}