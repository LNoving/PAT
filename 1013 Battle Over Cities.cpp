/**
 * 限时400ms，用scanf，程序跑完要160ms，用cin就超时了。第一次体会到scanf的可怕
 * */
#include<iostream>
#include<vector>
using namespace std;
int n, m, k, visit[1001], tmp;
vector<vector<int>> e;
void dfs(int p){
    visit[p] = 1;
    for(int i = 0; i < e[p].size(); i++){
        if(visit[e[p][i]] == 0)
            dfs(e[p][i]);
    }
}
int main(){
    cin >> n >> m >> k;
    e.resize(n + 1);
    for(int i = 0 ; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        //cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        cin >> tmp;
        int cnt = 0;
        fill(visit, visit + n + 1, 0);
        visit[tmp] = 1;
        for(int j = 1; j <= n; j++){
            if(visit[j] == 0){
                cnt++;
                dfs(j);
            }
        }
        cout << cnt - 1 << endl;
    }
}
