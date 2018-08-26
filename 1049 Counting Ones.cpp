#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int n;
int main(){
	int i;
	int count = 0;
	cin >> n;
	int p, pre, next;
	for (i = 1; n / (int)pow((double)10, (double)i - 1) != 0; i++) {
		p = n % (int)pow((double)10, (double)i) / (int)pow((double)10, (double)i - 1);
		pre = (int)n / pow((double)10, (double)i);
		next = n % (int)pow((double)10, (double)i - 1);
		if (p == 1) {
			//count += (int)n % (int)pow((double)10, (double)i );
			count += next + 1;
			count += (int)pre*(int)pow(10, (double)i - 1);
		}
		else if (n % (int)pow((double)10, (double)i) / (int)pow((double)10, (double)i - 1) == 0) {
			count += (int)pre*(int)pow(10, (double)i - 1);
		}
		else {
			count += (int)pre * pow(10, (double)i - 1);
			count += (int)pow((int)10, (int)i - 1);
		}
	}
	cout << count;

	return 0;
}