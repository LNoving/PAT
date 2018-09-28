#include <iostream>
using namespace std;
int n, m, e[201][201], k;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        int start, a, b, nn, flag = 1, visit[201] = {0};
        cin >> nn >> start;
        a = start;
        visit[a] = 1;
        for(int j = 1; j < nn; j++){
            cin >> b;
            if(e[a][b] != 1)flag = 0;
            visit[b] = 1;
            a = b;
        }
        for(int j = 1; j <= n; j++)
            if(visit[j] == 0)flag = 0;
        if(b != start || nn > n + 1)flag = 0;
        string s = flag == 1 ? "YES" : "NO";
        cout << s << endl;
    }
}
