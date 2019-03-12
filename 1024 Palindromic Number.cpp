#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    int n, k;
    cin >> s >> n;
    for(k = 0; k < n; k++){
        int flag = 1;
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            break;
        }
        string ans = "", rs = s;
        reverse(rs.begin(), rs.end());
        int c = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            int tmp = s[i] + rs[i] - '0' - '0';
            ans += (tmp + c) % 10 + '0';
            c = (tmp + c) / 10;
        }
        if(c){
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        s = ans;
    }
    cout << s << endl << k;
}
