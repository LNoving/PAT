#include <iostream>
using namespace std;
bool ispal(string s){
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}
string rev(string s){
    string tmp = s;
    for(int i = 0; i < s.length(); i++){
        tmp[i] = s[s.length() - 1 - i];
    }
    return tmp;
}
string opr(string s){
    string tmp, ans = "";
    tmp = rev(s);
    int c = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        int cur = ((tmp[i] - '0') + (s[i] - '0')) + c;
        char cc = cur % 10 + '0';
        ans += cc;
        if(cur >= 10)
            c = 1;
        else
            c = 0;
    }
    if(c == 1)
        ans += "1";
    ans = rev(ans);
    return ans;
}
int main(){
    string cur, tmp, sum;
    cin >> cur;
    sum = cur;
    for(int i = 0; i < 10; i++){
        if(ispal(cur))break;
        tmp = rev(cur);
        sum = opr(cur);
        cout << cur << " + " << tmp << " = " << sum << endl;
        cur = sum;
    }
    if(ispal(sum))
        cout << sum << " is a palindromic number.";
    else
        cout << "Not found in 10 iterations.";
}
