/**
 * �ܼ򵥵�һ���⣬�Ҿ�Ȼ����һ����Сʱ��ԭ����û������⣬���Ҹտ�ʼѡ��forѭ��
 * �ķ���Ҳ�ܷ������ĳ�while֮�����Լ�����
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
