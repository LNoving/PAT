#include <iostream>
using namespace std;
int n, m;
long int a[100010];
int main(){
    cin >> n;
    a[1] = 0;
    for(int i = 1; i < n; i++){
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    cin >> a[0] >> m;
    for(int i = 0; i < m; i++){
        int p, q;
        cin >> p >> q;
        if(p > q){
            int tmp = q;
            q = p;
            p = tmp;
        }
        long int ans = a[q] - a[p] < a[n] - a[q] + a[0] + a[p] ? a[q] - a[p] : a[n] - a[q] + a[0] + a[p];
        cout << ans << endl;
    }
}
