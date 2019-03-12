#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(isdigit(a[i])){
            i++;
            continue;
        }
        if(isdigit(b[j])){
            j++;
            continue;
        }
        if(a[i] != b[i])
            return a[i] < b[i];
    }
    return 1;
}
int main(){
    string tmp = "";
    map<string, int> m;
    char c = getchar();
    while(c != '\n'){
        if(isdigit(c) || isalpha(c)){
            if(c >= 'A' && c <= 'Z')
                c += 'a' - 'A';
            tmp += c;
        }
        else if(tmp.size() > 0){
            m[tmp]++;
            tmp = "";
        }
        c = getchar();
    }
    if(tmp.size() > 0)
        m[tmp]++;        //粗心！！！！！！！！
    int mx = -1;
    vector<string> ans;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second > mx){
            mx = it->second;
            ans.clear();
            ans.push_back(it->first);
        }
        else if(it->second == mx)
            ans.push_back(it->first);
    }
    sort(ans.begin(), ans.end(), cmp); // 这里不排序也能AC，但是按照题目要求应该是要排序的
    cout << ans[0] << " " << m[ans[0]];
}
