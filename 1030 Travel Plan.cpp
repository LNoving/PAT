//Dijkstra + DFS的套路。记住pre的用法。
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int e[500][500], cost[500][500], visit[500], dis[500];
vector<int> pre[500];
vector<int> path, temppath;
int mincost;
int INF = 99999999;
void dfs(int k){
    temppath.push_back(k);
    if(k == s){
        int tempcost = 0;
        int a = 0;
        for(int i = 1; i<temppath.size(); i++){
            tempcost += cost[temppath[a]][temppath[i]];
            a = i;
        }
        if(tempcost < mincost){
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for(int i = 0; i < pre[k].size(); i++){
        dfs(pre[k][i]);
    }
    temppath.pop_back();
}
int main(){
    fill(e[0], e[0] + 500*500,INF);
    fill(cost[0], cost[0] + 500, INF);
    fill(dis, dis + 500, INF);
    fill(visit, visit + 500, false);
    mincost = INF;
    cin >> n >> m >> s >> d;
    for(int i = 0 ;i < m; i++){
        int a, b;
        cin >> a >> b;
        cin >> e[a][b] >> cost[a][b];
        e[b][a] = e[a][b];
        cost[b][a] = cost[a][b];
    }
    dis[s] = 0;
    for(int i = 0; i<n; i++){
        int tdis = INF;
        int u = -1;
        for(int j = 0; j <n; j++){
            if( !visit[j] && dis[j] < tdis){
                tdis = dis[j];
                u = j;
            }
        }
        if(u == -1)break;
        visit[u] = true;
        for(int v = 0; v < n; v++){
            if(!visit[v] && e[u][v] < INF){
                if(dis[u] + e[u][v] < dis[v]){
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[u] + e[u][v] == dis[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(d);
    cout << s;
    for(int i = path.size() - 2; i>=0; i--){
        printf(" %d", path[i]);
    }
    printf(" %d %d", dis[d], mincost);
}