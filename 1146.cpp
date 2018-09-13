#include <vector>
#include <iostream>
using namespace std;
vector<int> v[1001];
int in[1001] = {0}, n, m, k, tmp[1001], flag = 0, test[1001];
int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n; j++){
            tmp[j] = in[j];
            cin >> test[j];
        }
        for(int j = 0; j < n; j++){
            if(tmp[test[j]] != 0){
                if(flag)cout << " ";
                cout << i;
                flag++;
                break;
            }
            for(int jj = 0; jj < v[test[j]].size(); jj++)
                tmp[v[test[j]][jj]]--;
        }
    }
}
