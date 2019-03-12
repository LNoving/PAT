#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s, ans = "";
    int a[10] = {0}, c = 0, flag = 1;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--){
        int tmp = s[i] - '0';
        a[tmp] ++;
        ans += (tmp * 2 + c) % 10 + '0';
        c = (tmp * 2 + c) / 10;
    }
    if(c){
        ans += '1';
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        int tmp = ans[i] - '0';
        a[tmp]--;
    }
    for(int i = 0; i < 10; i++)
        if(a[i] != 0)
            flag = 0;
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    cout << ans;
}
