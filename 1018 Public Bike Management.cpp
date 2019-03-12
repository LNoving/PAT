/**
 * 对于这种逻辑简单，但是代码略繁琐的题目，一定要一开始就思路清晰地写下去，写代码的时候要
 * 细心细心再细心！千万不能犯==这种简单的错误！！
 * */
#include <iostream>
#include <vector>
#define inf 999999999
using namespace std;
int c, n, m, sp, e[502][502], cur[502], visit[502] = {0}, dis[502], ansneed = inf, ansremain = inf;
vector<int> pre[502], tmppath, path;
void dfs(int k){
    if(k == 0){
        int need = 0, remain = 0;
        for(int i = tmppath.size() - 1; i >= 0; i--){
            int tmp = tmppath[i];
            if(cur[tmp] > c / 2){
                remain += cur[tmp] - c / 2;
            }
            else if(cur[tmp] < c / 2){
                if(remain >= c / 2 - cur[tmp])
                    remain -= c / 2 - cur[tmp];
                else{
                    need += (c / 2 - cur[tmp]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < ansneed || need == ansneed && remain < ansremain){
            path = tmppath;
            ansneed = need;
            ansremain = remain;
        }
    }
    tmppath.push_back(k);
    for(int i = 0; i < pre[k].size(); i++)
        dfs(pre[k][i]);
    tmppath.pop_back();
}
int main(){
    cin >> c >> n >> sp >> m;
    for(int i = 1; i <= n; i++)
        cin >> cur[i];
    n++;
    fill(e[0], e[0] + 502 * 502, inf);
    fill(dis, dis + 502, inf);
    for(int i = 0; i < m; i++){
        int a, b, len;
        cin >> a >> b >> len;
        e[a][b] = e[b][a] = len;
    }
    dis[0] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mini = inf;
        for(int j = 0; j < n; j++)
            if(visit[j] == 0 && dis[j] < mini){
                u = j;
                mini = dis[u];
            }
        if(u == -1)
            break;
        visit[u] = 1;
        for(int v = 0; v < n; v++){
            if(visit[v])
                continue;
            if(dis[u] + e[u][v] < dis[v]){
                dis[v] = dis[u] + e[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(dis[u] + e[u][v] == dis[v]){
                pre[v].push_back(u);
            }
        }
    }
    dfs(sp);
    cout << ansneed << " 0";
    for(int i = path.size() - 1; i >= 0; i--)
        cout << "->" << path[i];
    cout << " " << ansremain;
}