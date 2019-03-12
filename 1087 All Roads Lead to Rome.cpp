/*
第二遍训练，36min，一遍AC。时间基本都花在写代码上，没怎么debug。看来写代码的速度
还是太慢了。
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> pre[202];
vector<int> tmppath, anspath;
int  hpns[202], anshpns = 0, orig = 0, cnt = 0;
void dfs(int k){
    if(k == orig){
        int tmphpns = 0;
        cnt++;
        for(int i = 0; i < tmppath.size(); i++)
            tmphpns += hpns[tmppath[i]];
        if(tmphpns > anshpns || tmphpns == anshpns && tmppath.size() < anspath.size()){
            anspath = tmppath;
            anshpns = tmphpns;
        }
    }
    for(int i = 0; i < pre[k].size(); i++){
        tmppath.push_back(pre[k][i]);
        dfs(pre[k][i]);
        tmppath.pop_back();
    }
}
int main(){
    int n, k, e[202][202], inf = 999999999, dist[202], visit[202] = {0};
    string names[202];
    map<string, int> m;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int hp;
        if(i)
            cin >> hp;
        m[s] = i;
        names[i] = s;
        hpns[i] = hp;
    }
    fill(e[0], e[0] + 202 * 202, inf);
    fill(dist, dist + 202, inf);
    for(int i = 0; i < k; i++){
        string a, b;
        int l;
        cin >> a >> b >> l;
        e[m[a]][m[b]] = e[m[b]][m[a]] = l;
    }
    dist[orig] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mini = inf;
        for(int j = 0; j < n; j++)
            if(visit[j] == 0 && dist[j] < mini)
                u = j, mini = dist[j];
        if(u == -1)
            break;
        visit[u] = 1;
        for(int v = 0; v < n; v++){
            if(visit[v])
                continue;
            if(dist[u] + e[u][v] < dist[v]){
                dist[v] = dist[u] + e[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(dist[u] + e[u][v] == dist[v])
                pre[v].push_back(u);
        }
    }
    tmppath.push_back(m["ROM"]);
    dfs(m["ROM"]);
    printf("%d %d %d %d\n", cnt, dist[m["ROM"]], anshpns, anshpns / (anspath.size() - 1));
    cout << names[orig];
    for(int i = anspath.size() - 2; i >= 0; i--){
        cout << "->" << names[anspath[i]];
    }
}
/**
 * 很简单的一道题，竟然花了一个半小时。原因之一是Dijkstra写得还是太少了，不够熟悉。
 * 思维的清晰度，精准定位bug的能力还远远不够。还有，一定要先审清楚题目再做，不能急，
 * 一定要先看清楚题目要求的输出是什么。不然很可能白写很多代码。
 * */
/*
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int inf = 99999999, n, m, e[201][201], visit[201], happy[201], dis[201], nodes = inf, tmphap, maxhap, cnt;
vector <int> tmppath, path, pre[201];
map <string, int> cities;
string ids[201];
void dfs(int k){
    tmppath.push_back(k);
    tmphap += happy[k];
    if(k == 0){
        cnt++;
        if(tmphap > maxhap || (tmphap == maxhap && tmppath.size() < nodes)){
            nodes = tmppath.size();
            path = tmppath;
            maxhap = tmphap;
        }
    }
    else{
        for(int i = 0; i < pre[k].size(); i++){
            dfs(pre[k][i]);
        }
    }
    tmphap -= happy[k];
    tmppath.pop_back();
}
int main(){
    cin >> n >> m;
    string s;
    cin >> s;
    cities[s] = 0;
    ids[0] = s;
    for(int i = 1; i < n; i++){
        cin >> s;
        cities[s] = i;
        cin >> happy[i];
        ids[i] = s;
    }
    fill(e[0], e[0] + 201 * 201, inf);
    string a, b;
    int cost;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> cost;
        e[cities[a]][cities[b]] = cost;
        e[cities[b]][cities[a]] = cost;
    }
    fill(dis, dis + 201, inf);
    dis[0] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, minum = inf;
        for(int j = 0; j < n; j++){
            if(visit[j] == 0 && dis[j] < minum){
                minum = dis[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        visit[u] = 1;
        for(int v = 0; v < n; v++){
            if(visit[v] == 1 || e[u][v] == inf)
                continue;
            if(e[u][v] + dis[u] < dis[v]){
                pre[v].clear();
                pre[v].push_back(u);
                dis[v] = dis[u] + e[u][v];
            }
            else if(dis[u] + e[u][v] == dis[v]){
                pre[v].push_back(u);
            }
        }
    }
    int rom = cities["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cnt, dis[rom], maxhap, maxhap / (nodes - 1));
    cout << ids[0];
    for(int i = path.size() - 2; i >= 0; i--){
        printf("->");
        cout << ids[path[i]];
    }
}
*/