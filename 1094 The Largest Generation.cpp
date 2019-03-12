#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, level = 0;
    scanf("%d %d", &n, &m);
    vector<vector<int>> tree(n + 1);
    for(int i = 1; i <= m; i++){
        int cnt, k, temp;
        scanf("%d %d", &k, &cnt);
        for(int j = 0; j < cnt; j++){
            scanf("%d", &temp);
            tree[k].push_back(temp);
        }
    }
    vector<int> cur;
    pair<int, int> ans(0, 0);
    cur.push_back(1);
    while(!cur.empty()){
        level++;
        if(cur.size() > ans.second){
            ans.second = cur.size();
            ans.first = level;
        }
        vector<int> temp;
        for(int i = 0; i < cur.size(); i++){
            for(int j = 0; j < tree[cur[i]].size(); j++)
                temp.push_back(tree[cur[i]][j]);
        }
        cur = temp;
    }
    printf("%d %d", ans.second, ans.first);
    return 0;
}
