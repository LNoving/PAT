#include <iostream>
using namespace std;
int q[1010], row[1010], diag1[2010], diag2[2010];
int main(){
    int k, n, pos;
    cin >> k;
    for(int i = 0; i < k; i++){
        bool flag = true;
        fill(q, q + 1010, 0);
        fill(row, row + 1010, 0);
        fill(diag1, diag1 + 2010, 0);
        fill(diag2, diag2 + 2010, 0);
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> pos;
            if(row[pos] != 0 || diag1[j + pos - 1] != 0 || diag2[n - pos + j + 1] != 0)
                flag = false;
            row[pos] = 1;
            diag1[j + pos - 1] = 1;
            diag2[n - pos + j + 1] = 1;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
