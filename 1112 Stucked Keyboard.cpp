/**
 * 很简单的一道题，我竟然做了一个多小时。原因是没理解题意，并且刚开始选择for循环
 * 的方法也很繁琐。改成while之后明显简洁多了
 * */
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int k, i = 0, exist[256] = {0};
    cin >> k;
    string s;
    vector<char> rep;
    cin >> s;
    while(i < s.length()){
        int j = i;
        while(j - i < k && s[j] == s[i])j++;
        if(j - i == k){
            if(exist[int(s[i])] == 0){
                rep.push_back(s[i]);
                exist[(int)s[i]] = 1;
            }
            i = j;
        }
        else{
            while(i < j){
                exist[(int)s[i]] = -1;
                i++;
            }
        }
    }
    for(int i = 0; i < rep.size(); i++){
        if(exist[(int)rep[i]] != -1)
            printf("%c", rep[i]);
    }
    printf("\n");
    i = 0;
    while(i < s.length()){
        int j = i;
        while(j - i < k && s[j] == s[i])j++;
        if(j - i == k && exist[(int)s[i]] == 1){
            printf("%c", s[i]);
            i = j;
        }
        else{
            while(i < j){
                printf("%c", s[i]);
                i++;
            }
        }
    }
}
