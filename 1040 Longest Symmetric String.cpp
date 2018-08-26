#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
char str[1001];
int checksymodd(int n);
int checksymeven(int n);
int main() {
	int i = 0, j, k = 0, n, max = 1;
	while (1) {
		str[i] = getchar();
		if ( str[i] != '\n')i++;
		else break;
	}
	n = i;
	for (i = 0; i < n; i++) {
		k = checksymodd(i);
	    j = checksymeven(i);
		if (k > max)max = k;
		if (j > max)max = j;
	}
	cout << max;
}
int checksymodd(int n) {
	int i = 0;
	while (1) {
		if (n < i || i + n>1000)return 2 * i + 1;
		if (str[n - i - 1] == str[n + i + 1]) {
			i++;
		}
		else {
			return 2*i + 1;
		};
	}
}
int checksymeven(int n) {
	int i = 0;
	while (1) {
		if (n < i || n + i > 1000)return 2 * i;
		if (str[n - i] == str[n + i + 1])i++;
		else return 2 * i;
	}
}