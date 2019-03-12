#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(long int a, long int b){
    return a > b;
}
int main(){
    int nc, np;
    long int c[100010], p[100010], ans = 0;
    cin >> nc;
    for(int i = 0; i<nc; i++)
        cin >> c[i];
    cin >> np;
    for(int i = 0; i<np; i++)
        cin >> p[i];
    sort(c, c + nc, cmp);
    sort(p, p + np, cmp);
    int i = 0, j = nc - 1, x = 0, y = np - 1, flag = -1;
    while(i <= j && x <= y){
        if(c[i] > 0 && p[x] > 0){
            ans += c[i++] * p[x++];
        }
        if(c[j] < 0 && p[y] < 0){
            ans += c[j--] * p[y--];
        }
        if(flag == ans)
            break;
        else
            flag = ans;
    }
    cout << ans;
}