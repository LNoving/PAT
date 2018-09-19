/**
 * 系统提示“浮点错误”， 原因是除以0或者用0取余
 * */
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string num;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num;
        string a, b;
        a = num.substr(0, num.length() / 2);
        b = num.substr(num.length() / 2, num.length());
        int p, q;
        p = stoi(a);
        q = stoi(b);
        if( (p * q) != 0 && stoi(num) % (p * q) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
