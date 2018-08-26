#include <iostream>
#include <string>
using namespace std;
int main() {
	int ans = 0;
	string n;
	cin >> n;
	for (int i = 0; i < n.length(); i++)
		ans += n[i] - '0';
	string str[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string s = std::to_string(ans);
	for (int i = 0; i<s.length(); i++) {
		if (i)
			cout << " ";
		cout << str[(int)(s[i] - '0')];
	}
}