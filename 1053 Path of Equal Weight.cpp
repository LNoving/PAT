#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, w[101], tmps = 0;
vector <vector<int>> tree, path;
vector <int> tmppath;
bool cmp(int a, int b){
    return w[a] > w[b];
}
void dfs(int k){
    tmps += w[k];
    if(tmps > s){     //不能把这句和上一句合并在一起，因为赋值运算的优先级较低
        tmps -= w[k];
        return;
    }
    tmppath.push_back(k);
    if(tree[k].size()){
        for(int i = 0; i < tree[k].size(); i++)
            dfs(tree[k][i]);
    }
    else if(tmps == s){
        path.push_back(tmppath);
    }
    tmppath.pop_back();
    tmps -= w[k];
}
int main(){
    cin >> n >> m >> s;
    tree.resize(n);
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < m; i++){
        int tmp, k, nn;
        cin >> k >> nn;
        for(int i = 0; i < nn; i++){
            cin >> tmp;
            tree[k].push_back(tmp);
        }
        //输入完就排序
        sort(tree[k].begin(), tree[k].end(), cmp);
    }
    dfs(0);
    for(int i = 0; i < path.size(); i++){
        printf("%d", w[path[i][0]]);
        for(int j = 1; j < path[i].size(); j++)
            printf(" %d", w[path[i][j]]);
        printf("\n");
    }
}
