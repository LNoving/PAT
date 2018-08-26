#include<iostream>
#include<cstdio>
using namespace std;
int card[55], temp[55], result[55], n;
void out(int i) {
	if (i == 53) {
		cout << "J1";
		return;
	}
	if (i == 54) {
		cout << "J2";
		return;
	}
	switch ((i-1)/13)
	{
	    case 0:cout << "S"; break;
		case 1:cout << "H"; break;
		case 2:cout << "C"; break;
		case 3:cout << "D"; break;
	default:
		break;
	}
	if (i % 13 == 0)
		cout << 13;
	else
	    cout << i % 13;
}
void update() {
	int i;
	for (i = 1; i < 55; i++) {
		temp[card[i]] = result[i];
	}
	for (i = 1; i < 55; i++)
		result[i] = temp[i];
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i < 55; i++)
		cin >> card[i];
	for (int i = 1; i < 55; i++)
		result[i] = i;
	while(n--)
		update();
	for (int i = 1; i < 55; i++) {    //output
		if (i != 1)
			cout << " ";
		out(result[i]);
	}
	return 0;
}