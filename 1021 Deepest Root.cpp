/**
 * 太菜了。为数不多的一次AC之一。不过代码还是很丑。
 * 而且解法很低效。第三个case花了1200多ms 限制是1500ms，还是很危险的。
 * 大佬的解法：  https://www.liuchuo.net/archives/2348
 * 两次dfs。
 * */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[10001], ans;
int m = 0, visit[10001] = {0}, neww[10001] = {0}, depth = 0, root;
void dfs(int k){
    visit[k] = 1;
    neww[k] = 1;
    depth++;
    bool node = true;
    for(int i = 0; i<v[k].size(); i++){
        if(visit[v[k][i]] == 0){
            node = false;
            dfs(v[k][i]);
        }

    }
    if(node){
        if(depth > m){
            m = depth;
            ans.clear();
            ans.push_back(root);
        }
        else if(depth == m){
            if(ans.back() != root)
            ans.push_back(root);
        }
    }
    depth--;
}
int main() {
    int n, a, b, trees = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(root = 1; root<=n; root++){
        if(neww[root] == 0)trees++;
        fill(visit, visit + 10001, 0);
        dfs(root);
    }
    sort(ans.begin(),ans.end());
    if(trees > 1)printf("Error: %d components", trees);
    else
        for(int i = 0; i<ans.size(); i++)
            printf("%d\n", ans[i]);
}