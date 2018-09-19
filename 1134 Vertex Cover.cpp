#include <iostream>
#include <vector>
using namespace std;
int n, m, k, visit[10010];
vector <int> e[10010]; // e[i] represents the id of all the edges that incident to this vertex
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(i);
        e[b].push_back(i);
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        fill(visit, visit + m, 0);
        int kk, a, flag = 1;
        cin >> kk;
        for(int j = 0; j < kk; j++){
            cin >> a;
            for(int jj = 0; jj < e[a].size(); jj++)
                visit[e[a][jj]] = 1;
        }
        for(int jj = 0; jj < m; jj++)
            if(visit[jj] != 1){
                flag = 0;
                break;
            }
        if(flag == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
