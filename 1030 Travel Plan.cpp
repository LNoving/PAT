//之前是用Dijkstra + DFS的套路。后来发现可以不用dfs
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int e[500][500], cost[500][500], visit[500], dis[500], tmpcost[500], pre[500];
int INF = 99999999;
int main(){
    fill(e[0], e[0] + 500*500,INF);
    fill(cost[0], cost[0] + 500, INF);
    fill(dis, dis + 500, INF);
    fill(visit, visit + 500, false);
    fill(tmpcost, tmpcost + 500, INF);
    cin >> n >> m >> s >> d;
    for(int i = 0 ;i < m; i++){
        int a, b;
        cin >> a >> b;
        cin >> e[a][b] >> cost[a][b];
        e[b][a] = e[a][b];
        cost[b][a] = cost[a][b];
    }
    dis[s] = 0;
    tmpcost[s] = 0;
    for(int i = 0; i<n; i++){
        int tdis = INF, u = -1;
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
                if(dis[u] + e[u][v] < dis[v] ||
    dis[u] + e[u][v] == dis[v] && tmpcost[u] + cost[u][v] < tmpcost[v]){
                    dis[v] = dis[u] + e[u][v];
                    tmpcost[v] = tmpcost[u] + cost[u][v];
                    pre[v] = u;
                }
            }
        }
    }
    int a = d;
    vector<int> path(1, d);
    while(a != s){
        a = pre[a];
        path.push_back(a);
    }
    cout << s;
    for(int i = path.size() - 2; i>=0; i--){
        printf(" %d", path[i]);
    }
    printf(" %d %d", dis[d], tmpcost[d]);
}
