#include <iostream>
using namespace std;
int m, n, pre[10001], v[1000001], a, b;
int in(int l, int r){        // 我真的找不到我这个in函数bug在哪，估计是确定i的地方有问题。唉，算了，反正这个函数用不到
    if(a <= pre[l] && b >= pre[l])
        return pre[l];
    int i = l + 1;
    while(pre[i] < pre[l] && i <= r) i++;    //用这个确定i，倒数第二个case过不了。
    //i = (l + r) / 2;  //用这个确定i竟然只有最后一个case没过。
    if(b < pre[l])
        return in(l + 1, i - 1);
    else
        return in(i, r);
}
bool check(int a, int b){
    if((a < 0 || v[a] != 1) && (b < 0 || v[b] != 1)){
        printf("ERROR: %d and %d are not found.\n", a, b);
        return false;
    }
    else if (a < 0 || v[a] != 1){
        printf("ERROR: %d is not found.\n", a);
        return false;
    }
    else if (b < 0 || v[b] != 1){
        printf("ERROR: %d is not found.\n", b);
        return false;
    }
    return true;
}
int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> pre[i];
        v[pre[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        int x = a, y = b;
        if(!check(a, b)){
            continue;
        }
        if(a > b)
            swap(a, b);
        int ans;
        //ans = in(0, n - 1);
        for(int j = 0; j < n; j++)
            if(a <= pre[j] && b >= pre[j]){
                ans = pre[j];
                break;
            }
        if(ans == a || ans == b)
            printf("%d is an ancestor of %d.\n", ans, ans == a ? b : a);
        else
            printf("LCA of %d and %d is %d.\n", x, y, ans);
    }
}
