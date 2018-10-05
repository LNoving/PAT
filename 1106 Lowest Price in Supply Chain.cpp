#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, lest = 100001, cnt;
double r, cost, price;
vector<int> v[100001];
void dfs(int k, int lev){
    lev++;
    for(int i = 0; i < v[k].size(); i++){
        dfs(v[k][i], lev);
    }
    if(v[k].size() == 0){
        if(lev < lest){
            lest = lev;
            cnt = 1;
        }
        else if(lev == lest){
            cnt++;
        }
    }
}
int main(){
    cin >> n >> cost >> r;
    for(int i = 0; i < n; i++){
        int k, a;
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> a;
            v[i].push_back(a);
        }
    }
    dfs(0, 0);
    price = pow(1 + 0.01 * r, lest - 1) * cost;
    printf("%.4f %d", price, cnt);
}
