#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> hobby[1002], ans;
int n, fa[1002], cnt[1002];
bool cmp(int a, int b){
    return a > b;
}
int find_fa(int k){
    int root = k;
    while(root != fa[root])
        root = fa[root];
    while(k != root){
        int tmp = fa[k];
        fa[k] = root;
        k = tmp;
    }
    return root;
}
void uni(int a, int b){
    int aa = find_fa(a), bb = find_fa(b);
    if(aa != bb){
        fa[aa] = bb;
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int k, h;
        scanf("%d: ", &k);
        for(int j = 0; j < k; j++){
            cin >> h;
            hobby[h].push_back(i);
        }
        fa[i] = i;
    }
    for(int i = 1; i < 1002; i++){
        for(int j = 1; j < hobby[i].size(); j++){
            uni(hobby[i][0], hobby[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        int k = find_fa(i);
        cnt[k]++;
    }
    for(int i = 1; i <= n; i++)
        if(cnt[i] > 0)
            ans.push_back(cnt[i]);
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n%d", ans.size(), ans[0]);
    for(int i = 1; i < ans.size(); i++){
        printf(" %d", ans[i]);
    }
}
