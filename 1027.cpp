#include <iostream>
using namespace std;
int main(){
    int a;
    char s[14] = "0123456789ABC";
    cout << "#";
    for(int i = 0; i < 3; i++){
        cin >> a;
        cout << s[a/13];
        cout << s[a%13];
    }
}