#include <iostream>
#include <vector>
using namespace std;
int n, m, flag = 2, visit[510];
vector <int> e[510];
void dfs(int p){
    if(visit[p] == 1)return;
    visit[p] = 1;
    for(int i = 0; i < e[p].size(); i++){
        int cur = e[p][i];
        dfs(cur);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);
    int odd = 0;
    for(int i = 1; i <= n; i++){
        if(visit[i] != 1){
            flag = 0;
            break;
        }
        if(e[i].size() % 2 == 1){
            flag = 1;
            odd ++;
        }
        if(odd > 2){
            flag = 0;
            break;
        }
    }
    printf("%d", e[1].size());
    for(int i = 2; i <= n; i++){
        printf(" %d", e[i].size());
    }
    string a[3] = {"Non-Eulerian", "Semi-Eulerian", "Eulerian"};
    cout << "\n" << a[flag];
}
/* 下面是利用dfs死找答案。有bug，case4 过不去， case6超时，懒得改了。把这道题想复杂了
#include <iostream>
#include <vector>
using namespace std;
int n, m, flag = 0, visit[510][510], last, cnt, root;
vector <int> e[510];
void dfs(int p){
    for(int i = 0; i < e[p].size(); i++){
        int cur = e[p][i];
        if(visit[p][cur] == 1)continue;
        visit[p][cur] = 1;
        visit[cur][p] = 1;
        last = cur;
        cnt++;
        if(flag != 2 && cnt == m){
            flag = last == root ? 2 : 1;
        }
        dfs(cur);
        visit[p][cur] = 0;
        visit[cur][p] = 0;
        cnt--;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(root = 1; root <= n; root++){
        fill(visit[0], visit[0] + 510 * 510, 0);
        last = 0;
        cnt = 0;
        dfs(root);
        if(flag == 2)break;
    }
    printf("%d", e[1].size());
    for(int i = 2; i <= n; i++){
        printf(" %d", e[i].size());
    }
    string a[3] = {"Non-Eulerian", "Semi-Eulerian", "Eulerian"};
    cout << "\n" << a[flag];
}
*/
