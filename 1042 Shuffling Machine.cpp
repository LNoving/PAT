#include <cstdio>
#include <vector>
using namespace std;
int main(){
    vector<int> arr(55);
    int n, sh[55];
    scanf("%d", &n);
    for(int i = 1; i <= 54; i++){
        arr[i] = i;
        scanf("%d", &sh[i]);
    }
    for(int i = 0; i < n; i++){
        vector<int> temp(55);
        for(int i = 1; i <= 54; i++)
            temp[sh[i]] = arr[i];
        arr = temp;
    }
    char s[] = "SHCDJ";
    for(int i = 1; i <= 54; i++){
        if(i != 1) printf(" ");
        printf("%c%d", s[(arr[i] - 1) / 13], (arr[i] - 1) % 13 + 1);
    }
}

/*  对比一下半年前的代码和现在的代码，看来努力还是有点用的吧。
#include<iostream>
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
*/