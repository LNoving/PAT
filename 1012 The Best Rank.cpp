#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct Student {
	string id;
	int c;
	int m;
	int e;
	int sum;
};
bool judge(int a, int b);
bool judge(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	Student stu[2000];
	string check[2000];
	int c[2000] = { 0 };
	int math[2000] = { 0 };
	int e[2000] = { 0 };
	int sum[2000] = { 0 };
	cin >> n >> m;
	for (int i = 0; i<n; i++) {
		cin >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
		stu[i].sum = stu[i].c + stu[i].m + stu[i].e;
		c[i] = stu[i].c;
		math[i] = stu[i].m;
		e[i] = stu[i].e;
		sum[i] = stu[i].sum;
	}

	for (int i = 0; i<m; i++) {
		cin >> check[i];
	}

	sort(c, c + n, judge);
	sort(e, e + n, judge);
	sort(math, math + n, judge);
	sort(sum, sum + n, judge);

	for (int i = 0; i<m; i++) {
		if (i)
			cout << "\n";
		int j;
		int rk[5];
		for (j = 0; j<n; j++) {
			if (stu[j].id == check[i]) {
				break;
			}
		}
		if (stu[j].id != check[i]) {
			cout << "N/A";
			continue;
		}
		int k;
		for (k = 0; k<n; k++) {
			if (stu[j].sum == sum[k])
				break;
		}
		rk[0] = k;
		for (k = 0; k<n; k++) {
			if (stu[j].c == c[k])
				break;
		}
		rk[1] = k;
		for (k = 0; k<n; k++) {
			if (stu[j].m == math[k])
				break;
		}
		rk[2] = k;
		for (k = 0; k<n; k++) {
			if (stu[j].e == e[k])
				break;
		}
		rk[3] = k;
		rk[4] = 2001;
		int mk = 4;
		for (k = 0; k<4; k++) {
			if (rk[k] < rk[mk])
				mk = k;
		}
		cout << rk[mk] + 1;
		switch (mk) {
		case 0: cout << " A"; break;
		case 1: cout << " C"; break;
		case 2: cout << " M"; break;
		case 3: cout << " E"; break;
		default:;
		}
	}
}