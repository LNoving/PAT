#include <iostream>
using namespace std;
int main(){
    int n;
    string s, ans;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        getline(cin, s);
        if(i == 0){
            ans = s;
            continue;
        }
        for(int j = 0; j < ans.size() && j < s.size(); j++){
            if(ans[ans.size() - 1 - j] != s[s.size() - 1 - j]){
                ans = ans.substr(ans.size() - j);
                break;
            }
        }
        if(ans.size() == 0) break;
    }
    if(ans.size() == 0)
        cout << "nai" << endl;
    else
        cout << ans << endl;
}
