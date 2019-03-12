/**
 * 有的节点是多余的。
 * */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int p, val, next;
} arr[100001];
bool cmp(node a, node b){
    return a.val < b.val;
}
int main(){
    int n, start;
    vector<node> ans;
    cin >> n >> start;
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        arr[k].p = k;
        scanf("%d %d", &arr[k].val, &arr[k].next);
    }
    while(start != -1){
        ans.push_back(arr[start]);
        start = arr[start].next;
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d ", ans.size());
    for(int i = 0; i < ans.size(); i++){
        printf("%05d\n%05d %d ", ans[i].p, ans[i].p, ans[i].val);
    }
    printf("-1\n");
}
