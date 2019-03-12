#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int p, val, next;
};
int main(){
    node arr[100010];
    int n, p, k, cnt = 0;
    cin >> p >> n >> k;
    for(int i = 0; i < n; i++){
        int kk;
        cin >> kk;
        cin >> arr[kk].val >> arr[kk].next;
        arr[kk].p = kk;
    }
    vector<node> v;
    while(p != -1){
        v.push_back(arr[p]);
        p = arr[p].next;
        cnt++;
    }
    for(int i = 1; i <= cnt / k; i++){
        reverse(v.begin() + (i - 1) * k, v.begin() + i * k);
    }
    for(int i = 0; i < cnt; i++){
        if(i)
            printf("%05d\n", v[i].p);
        printf("%05d %d ", v[i].p, v[i].val);
    }
    printf("-1\n");
}
