#include <iostream>
#include <vector>
using namespace std;
int cnt[101], n, m, deepest = 0;
vector<int> tree[101];
void dfs(int k, int lev){
    lev++;
    if(tree[k].size() == 0){
        cnt[lev]++;
        if(lev > deepest)
            deepest = lev;
        return;
    }
    for(int i = 0; i < tree[k].size(); i++){
        dfs(tree[k][i], lev);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int k, nn, tmp;
        cin >> k >> nn;
        for(int j = 0; j < nn; j++){
            cin >> tmp;
            tree[k].push_back(tmp);
        }
    }
    dfs(01, 0);
    for(int i = 1; i <= deepest; i++){
        if(i != 1)
            printf(" ");
        printf("%d", cnt[i]);
    }
}
