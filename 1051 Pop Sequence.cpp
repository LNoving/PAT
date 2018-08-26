#include <cstdio>
#include <iostream>
using namespace std;
int cap, len, n, a[1000];
int check() {
	int k = 0, p = 1, result = 1, t;
	for (int i = 0; i < 1000; i++)
		a[i] = -1;
	for (int j = 0; j < len; j++) {
		cin >> t;
		while (k<=cap) {
			if (a[k] == t) {
				a[k--] = -1;//pop
				break;
			}
			a[++k] = p++;  //push
		}
		if (k > cap || p>len+1)
			result = 0;
	}
	return result;
}
int main() {
	cin >> cap >> len >> n;
	int b[1000];
	for (int i = 0; i < n; i++) {
		b[i] = check();
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << "\n";
		if (b[i])
			cout << "YES";
		else
			cout << "NO";
	}
}