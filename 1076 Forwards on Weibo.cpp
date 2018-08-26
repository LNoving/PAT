/***
 * 一次性AC，题目很简单，代码也很快写完了。但是debug花了很久。比如如何防止循环，针对特定
 * 题目的细节还是要考虑清楚。
 * PS 大佬用到了queue，
 * */
#include <iostream>
#include <vector>
using namespace std;
int n, l, k, ask[10001], nask, visit[10001] = {0}, layer, root, ans[10001] = {0};
vector<vector<int>> m;
void dfs(int p){
    layer++;
    if(layer > k){layer--; return;}
    visit[p] = layer;
    if(p == root)visit[p] = 1;
    for(int i = 0; i < m[p].size(); i++){
        if(visit[m[p][i]] == 0 && layer < k){
            dfs(m[p][i]);
            ans[root]++;
        }else if(visit[m[p][i]] > layer + 1 && layer < k){
            dfs(m[p][i]);
        }
    }
    layer--;
}
int main() {
    cin >> n >> k;
    m.resize(n + 1);
    for(int i = 1; i<=n; i++){
        int fols, tmp;
        cin >> fols;
        for(int j = 0; j<fols; j++){
            cin >> tmp;
            m[tmp].push_back(i);
        }
    }
    cin >> nask;
    for(int i = 0; i<nask; i++){
        cin >> root;
        layer = -1;
        fill(visit, visit + 10001, 0);
        dfs(root);
        cout << ans[root] << endl;
    }
    getchar();
}
