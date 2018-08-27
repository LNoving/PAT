#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int n, k;
set<int> s[51], all;
int main(){
    cin >> n ;
    for(int i = 1; i <= n; i++){
        int m, tmp;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> tmp;
            s[i].insert(tmp);
        }
    }
    cin >> k;
    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        int tmp = 0;
        for(auto it = s[a].begin(); it != s[a].end(); it++){
            if(s[b].find(*it) != s[b].end())
                tmp++;
        }
        float ans = (float) tmp / (float)(s[a].size() + s[b].size() - tmp) * 100;
        if(i)printf("\n");
        printf("%.1f%%", ans);
    }
}