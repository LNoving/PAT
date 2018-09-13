/**
 * Á·Ï°£¬25min¡£
 * */
#include <set>
#include <vector>
#include <iostream>
using namespace std;
int exist[100010], n, m;
vector<int> dan[100010];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        dan[a].push_back(b);
        dan[b].push_back(a);
    }
    for(int i = 0; i < m; i++){
        int nn, a, j, k, flag = 1;
        cin >> nn;
        if(i != 0)cout << "\n";
        fill(exist, exist + 100010, 0);
        for(int j = 0; j < nn; j++){
            cin >> a;
            for(k = 0; k < dan[a].size(); k++)
                if(exist[dan[a][k]] == 1)flag = 0;
            else{
                exist[a] = 1;
            }
        }
        if(flag)
            cout << "Yes";
        else
            cout << "No";
    }
}