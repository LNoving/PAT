/**
 * 大佬的解法。
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
//weight是点权，w是路径上的点权,num是路径的条数
bool visit[510];
const int inf = 99999999;
int main() {
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i<n; i++)
        cin >> weight[i];
    fill(e[0],e[0] + 510*510, inf);
    fill(dis, dis + 510, inf);
    fill(visit, visit + 501, false);
    int a, b, c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;  ///很关键 跪了
    for(int i = 0; i<n; i++){
        int d = inf, k = -1;
        for(int j = 0; j<n; j++){
            if(visit[j])continue;
            if(dis[j] < d){
                d = dis[j];
                k = j;
            }
        }
        if(k == -1)break;     /// k = -1  结束的判定
        visit[k] = true;
        for(int j = 0; j<n; j++){
            if(visit[j] == true || e[k][j] == inf)continue;
            if(dis[k] + e[k][j] < dis[j]){
                dis[j] = dis[k] + e[k][j];
                num[j] = num[k];
                w[j] = w[k] + weight[j];
            }
            else if(dis[k] + e[k][j] == dis[j]){
                num[j] = num[k] + num[j];              ///这里做错了
                w[j] = max(w[k] + weight[j],w[j]);
            }
        }
    }
    printf("%d %d",num[c2], w[c2]);
    return 0;
}