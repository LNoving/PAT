/**
感觉这种题对时间的要求也不算特别高。不需要想太多。常规方法就可以
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n, k;
const int couses = 2501;
vector<int> v[couses];
int gethash(char* name){
    int ans = (int)(name[0] - 'A');
    ans *= 26;
    ans += (int)(name[1] - 'A');
    ans *= 26;
    ans += (int)(name[2] - 'A');
    ans *= 10;
    ans += (int)(name[3] - '0');
    return ans;
}
void getname(int h, char* ans){
    ans[3] = (char) (h%10 + '0');
    h /= 10;
    ans[2] = (char) (h%26 + 'A');
    h /= 26;
    ans[1] = (char) (h%26 + 'A');
    h /= 26;
    ans[0] = (char) (h + 'A');
    ans[4] = '\0';
    return;
}
int main(){
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s", &name);
        int a, b;
        int h = gethash(name);
        scanf("%d", &a);
        for(int j = 0; j<a; j++){
            scanf("%d", &b);
            v[b].push_back(h);
        }
    }
    for(int i = 1; i<=k; i++){
        printf("%d %d\n", i, v[i].size());
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j<v[i].size(); j++){
            getname(v[i][j],name);
            printf("%s\n", name);
        }
    }
}
