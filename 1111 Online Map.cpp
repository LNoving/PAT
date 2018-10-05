/**
 * 题目比较简单。代码有点长，输出格式比较麻烦。因为写输出部分的时候手滑写错了一个变量，
 * 导致主case过不去。曾一度怀疑是代码逻辑的问题。。。
 * 这道题在贪心的时候直接可以得到最优解，不需要dfs。动手写之前如果能想清楚这点就可以
 * 节省很多代码量。我就是先做完才反过来想清楚的。
 * 输出部分参考了别人的代码，自己第一次写出来的那个感觉不是很优雅。
 * */
#include <iostream>
#include <vector>
using namespace std;
int n, m, source, dest, len[501][501], tim[501][501], inf = 999999, visit[501], dis[501], path[501], len_time[501], dis_sum = 0, nodes[501];
vector<int> ans1, ans2;
int main(){
    cin >> n >> m;
    fill(len[0], len[0] + 501 * 501, inf);
    fill(tim[0], tim[0] + 501 * 501, inf);
    for(int i = 0; i < m; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        len[a][b] = d;
        tim[a][b] = e;
        if(!c){
            len[b][a] = d;
            tim[b][a] = e;
        }
    }
    cin >> source >> dest;
    fill(visit, visit + 501, 0);
    fill(dis, dis + 501, inf);
    fill(len_time, len_time + 501, inf);
    dis[source] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mindis = inf;
        for(int j = 0; j < n; j++){
            if(visit[j] == 1)
                continue;
            if(dis[j] < mindis){
                u = j;
                mindis = dis[u];
            }
        }
        if(u == -1)
            break;
        visit[u] = 1;
        for(int v = 0; v < n; v++){
            if(visit[v] == 1 || len[u][v] == inf)
                continue;
            if(len[u][v] + dis[u] < dis[v]){
                dis[v] = dis[u] + len[u][v];
                path[v] = u;
                len_time[v] = tim[u][v] + len_time[u];
            }
            else if(dis[u] + len[u][v] == dis[v]){
                if(tim[u][v] + len_time[u] < len_time[v]){
                    path[v] = u;
                    len_time[v] = tim[u][v] + len_time[u];
                }
            }
        }
    }
    dis_sum = dis[dest];
    int a = dest;
    ans1.push_back(dest);
    while(a != source){
        a = path[a];
        ans1.push_back(a);
    }
    fill(visit, visit + 501, 0);
    fill(dis, dis + 501, inf);
    fill(nodes, nodes + 501, inf);
    nodes[source] = 0;
    dis[source] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mindis = inf;
        for(int j = 0; j < n; j++){
            if(visit[j] == 1)
                continue;
            if(dis[j] < mindis){
                u = j;
                mindis = dis[u];
            }
        }
        if(u == -1)
            break;
        visit[u] = 1;
        for(int v = 0; v < n; v++){
            if(visit[v] == 1 || tim[u][v] == inf)
                continue;
            if(tim[u][v] + dis[u] < dis[v]){
                dis[v] = dis[u] + tim[u][v];
                path[v] = u;
                nodes[v] = nodes[u] + 1;
            }
            else if(tim[u][v] + dis[u] == dis[v]){
                if(nodes[u] + 1 < nodes[v]){
                    dis[v] = dis[u] + tim[u][v];
                    path[v] = u;
                    nodes[v] = nodes[u] + 1;
                }
            }
        }
    }
    a = dest;
    ans2.push_back(a);
    while(a != source){
        a = path[a];
        ans2.push_back(a);
    }
    printf("Distance = %d", dis_sum);
    if(ans1 == ans2){  //    要知道vector是可以直接比较的
        printf("; Time = %d: %d", dis[dest], source);
    }
    else{
        printf(": %d", source);
        for(int i = ans1.size() - 2; i >= 0; i--)
            printf(" -> %d", ans1[i]);
        printf("\nTime = %d: %d", dis[dest], source);
    }
    for(int i = ans2.size() - 2; i >= 0; i--)
        printf(" -> %d", ans2[i]);
}