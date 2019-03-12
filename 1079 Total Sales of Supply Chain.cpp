#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, level = 0, leaves[100010];
double p, r, total = 0.0;
vector<vector<int>> tree;
void dfs(int k){
    if(leaves[k] == 1){
        total += p * pow(1.0 + r / 100.0, level) * tree[k][0];
        return;
    }
    level++;
    for(int i = 0; i < tree[k].size(); i++){
        dfs(tree[k][i]);
    }
    level--;
}
int main(){
    cin >> n >> p >> r;
    tree.resize(n);
    for(int i = 0; i < n; i++){
        int cnt, temp;
        scanf("%d", &cnt);
        if(cnt == 0){
            leaves[i] = 1;
            scanf("%d", &temp);
            tree[i].push_back(temp);
        }
        for(int j= 0; j < cnt; j++){
            scanf("%d", &temp);
            tree[i].push_back(temp);
        }
    }
    dfs(0);
    printf("%.1f", total);
}
