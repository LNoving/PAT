/**
 * 没什么意思。所有的Gi都要算到路径里面。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int e[1012][1012], n, m, k, dist[1012], visit[1012], inf = 999999, ans = -1, ansmin = 0, anstotal = inf, dx;
int main(){
    fill(e[0], e[0] + 1012 * 1012, inf);
    cin >> n >> m >> k >> dx;
    for(int i = 0; i < k; i++){
        string s1, s2;
        int length, a1, a2;
        cin >> s1 >> s2 >> length;
        if(s1[0] == 'G'){
            s1 = s1.substr(1);
            a1 = stoi(s1.c_str()) + n;
        }
        else
            a1 = stoi(s1.c_str());
        if(s2[0] == 'G'){
            s2 = s2.substr(1);
            a2 = stoi(s2.c_str()) + n;
        }
        else
            a2 = stoi(s2.c_str());
        e[a1][a2] = length, e[a2][a1] = length;
    }
    for(int i = 1; i <= m; i++){
        int start = n + i, totaldist = 0, mi = inf, mx = 0;
        fill(visit + 1, visit + 1 + n + m, 0);
        fill(dist, dist + 1 + n + m, inf);
        dist[start] = 0;
        while(1){
            int u = -1, mini = inf;
            for(int l = 1; l <= n + m; l++)
                if(visit[l] == 0 && dist[l] < mini)
                    u = l, mini = dist[l];    // 忘了更新mini
            if(u == -1) break;
            visit[u] = 1;     //这里不小心写成了 == 瞅了十几分钟
            for(int v = 1; v <= n + m; v++){
                if(visit[v] == 1)
                    continue;
                if(e[u][v] + dist[u] < dist[v])
                    dist[v] = e[u][v] + dist[u];
            }
        }
        for(int j = 1; j <= n; j++){
            totaldist += dist[j];
            if(j <= n)
            mi = min(mi, dist[j]);
            mx = max(mx, dist[j]);
        }
        if(mx <= dx && mi > ansmin || (totaldist < anstotal && mi == ansmin)){
            ans = i, ansmin = mi, anstotal = totaldist;
        }
    }
    if(ans == -1)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f", ans, 1.0 * ansmin, anstotal * 1.0 /n);
}
