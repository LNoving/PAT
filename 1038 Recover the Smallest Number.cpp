/**
 * 考虑相同开头不同长度的string比较的时候，最先想到类似KPM的重叠比较方法，因为涉及
 * 到交换，逻辑还比较绕，差点把自己绕晕了。后来一想，妈的，这么简单个问题让我搞这
 * 么复杂。case 3真不要脸，不就是一个0么，有什么好卡的，和题目要求一点有矛盾。
 * */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string strs[10001];
int n;
bool cmp(string a, string b){
    for(int i = 0; i<min(a.length(), b.length()); i++){
        if(a[i] < b[i])return true;
        if(a[i] > b[i])return false;
    }
    string c = a + b, d = b + a;
    if (c == d)return true;
    return cmp(c, d);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> strs[i];
    sort(strs, strs + n, cmp);
    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < strs[i].length(); j++){
            if(strs[i][j] == '0' && flag)continue;
            flag = false;
            cout << strs[i][j];
        }
    }
    if(flag == true)
        cout << "0";
}
