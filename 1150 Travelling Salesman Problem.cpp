#include <iostream>
using namespace std;
int e[210][210], n, m, k, INF = 9999999, visit[210], mini = 9999999, minik; // -1 not visit 2 not simple  1 simple  3 not exist
int main(){
    fill(e[0], e[0] + 210 * 210, INF);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        int pre, cur = 0, nn, len = 0, stat = 0, start;
        fill(visit, visit + 210, 0);
        cin >> nn;  /// nn == 1 ??
        cin >> start;
        pre = start;
        for(int j = 1; j < nn; j++){
            cin >> cur;
            if(e[pre][cur] == INF || stat == 3){
                stat = 3;
                continue;
            }
            len += e[pre][cur];
            visit[cur] = 1;
            pre = cur;
        }
        if(stat == 3){
            printf("Path %d: NA (Not a TS cycle)\n", i);
            continue;
        }
        for(int j = 1; j <= n; j++)
            if(visit[j] == 0)
                stat = -1;
        if(cur != start || stat == -1){
            printf("Path %d: %d (Not a TS cycle)\n", i, len);
            continue;
        }
        if(len < mini){
            mini = len;
            minik = i;
        }
        if(nn > n + 1){
            printf("Path %d: %d (TS cycle)\n", i, len);
            continue;
        }
        printf("Path %d: %d (TS simple cycle)\n", i, len);
    }
    printf("Shortest Dist(%d) = %d", minik, mini);
}
/**
 * 考试时候写的代码，逻辑比较乱，东拼西凑的，但是逻辑没有问题。所有的bug都出在那
 * 一个break上。这个break直接导致我放弃了这次考试。菜是原罪。
 * */
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
int n, m, e[210][210], path[210] = {-1}, k, mi = 999999999, inf = 99999999, visit[210] = {0}, ans[5000][2], mno;
int main(){
    cin >> n >> m;
    int a, b;
    fill(e[0], e[0] + 210 * 210, inf);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cin >> e[a][b];
        e[b][a] = e[a][b];
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        int nn, cur, nxt, tmpdis = 0, flag = 1;
        fill(visit, visit + 210, 0);
        cin >> nn >> cur;
        int start = cur;
        for(int j = 1; j < nn ; j++){
            cin >> nxt;
            if(e[cur][nxt] == inf){
                flag = 0;
                //break;
            }
            visit[nxt] = 1;
            tmpdis += e[cur][nxt];
            cur = nxt;
        }
        if(flag == 0)tmpdis = -1;
        for(int j = 1; j <= n; j++){
            if(visit[j] != 1){
                flag = 0;
            }
        }
        if(nxt != start)flag = 0;    //没有这句也能过
        ans[i][0] = tmpdis;
        ans[i][1] = flag;
        if(flag == 1 && nn > n + 1)ans[i][1] = -1;
        if(tmpdis!= -1 && flag != 0 && tmpdis < mi){
            mi = tmpdis;
            mno = i;
        }
    }
    for(int i = 1; i <= k; i++){
        cout << "Path " << i << ": ";
        if(ans[i][0] == -1)
            cout << "NA (Not a TS cycle)";
        else if(ans[i][1] == -1)
            cout << ans[i][0] << " (TS cycle)";
        else if (ans[i][1] == 0)
            cout << ans[i][0] << " (Not a TS cycle)";
        else if (ans[i][1] == 1)
            cout << ans[i][0] << " (TS simple cycle)";
        cout << "\n";
    }
    printf("Shortest Dist(%d) = %d", mno, mi);
};
*/
