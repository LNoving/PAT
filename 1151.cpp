#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int m, n, in[10010], pre[10010], x, y;
map<int,int> pos;
bool check(int p, int q){
    x = pos[p];   ///注意，map中的元素默认为0；
    y = pos[q];
    if(x == 0 && y == 0){
        cout << "ERROR: "<< p <<" and "<< q <<" are not found.";
        return false;
    }else if(x == 0){
        cout << "ERROR: "<< p << " is not found.";
        return false;
    }else if(y == 0){
        cout << "ERROR: "<< q << " is not found.";
        return false;
    }
    return true;
}
int build(int inl, int inr, int k){
    int i = pos[pre[k]];
    if(x <= i && y >= i)return pre[k];
    if(x < i && y < i)return build(inl, i - 1, k + 1);
    if(x > i && y > i)return build(i + 1, inr, k + i - inl + 1);
}
int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> in[i];
        pos[in[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        cin >> pre[i];
    for(int i = 0; i < m; i++){
        int p, q;
        if(i)cout << endl;
        cin >> p >> q;
        if(check(p, q) == false)continue;
        if(x > y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        int ans = build(1, n, 1);
        if(ans == p)
            printf("%d is an ancestor of %d.", p, q);
        else if(ans == q)
            printf("%d is an ancestor of %d.", q, p);
        else
            printf("LCA of %d and %d is %d.", p, q, ans);
    }
}
