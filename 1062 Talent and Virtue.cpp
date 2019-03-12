#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int id, v, t;
} arr[100001];
int n, l, h, total;
int type(node a){
    if(a.v < l || a.t < l)
        return 4;
    if(a.v >= h && a.t >= h)
        return 0;
    if(a.t < h && a.v >= h)
        return 1;
    if(a.v < h && a.t < h && a.v >= a.t)
        return 2;
    return 3;
}
bool cmp(node a, node b){
    int ta = type(a), tb = type(b);
    if(ta != tb)
        return ta < tb;
    else if (a.t + a.v != b.t + b.v)
        return a.t + a.v > b.t + b.v;
    else
        return a.v != b.v ? a.v > b.v : a.id < b.id;
}
int main(){
    cin >> n >> l >> h;
    for(int i = 0; i < n; i++)
        cin >> arr[i].id >> arr[i].v >> arr[i].t;
    sort(arr, arr + n, cmp);
    for(total = 0; total < n; total++)
        if(arr[total].v < l || arr[total].t < l)
            break;
    cout << total << endl;
    for(int i = 0; i < total; i++)
        printf("%08d %d %d\n", arr[i].id, arr[i].v, arr[i].t);
}
