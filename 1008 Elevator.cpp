#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
	int a, b, n;
	cin >> n;
	int ans = 0;
	a = 0;
	for (int i = 0; i< n; i++) {
		cin >> b;
		if (b > a)
			ans += (b - a) * 6 + 5;
		else if (b < a)
			ans += (a - b) * 4 + 5;
		else
			ans += 5; //坑在这里。题目没说清楚
		a = b;
	}
	cout << ans;
}