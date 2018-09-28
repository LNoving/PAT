#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int l, r, po;
};
int n, in[31], post[31], lev = 0;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    vector <node> cur;
    vector <int> ans[32];
    cur.push_back(*new node{0, n - 1, n - 1});
    while(!cur.empty()){
        vector<node> tmp;
        for(int i = 0; i < cur.size(); i++){
            int l = cur[i].l, r = cur[i].r, po = cur[i].po, k = l;
            if(l > r)continue;
            while(in[k] != post[po] && k <= r)k++;
            ans[lev].push_back(post[po]);
            tmp.push_back(*new node{l, k - 1, po - (r - k) - 1});
            tmp.push_back(*new node{k + 1, r, po - 1});
        }
        if(lev % 2 == 0)
            reverse(ans[lev].begin(), ans[lev].end());
        cur = tmp;
        lev++;
    }
    printf("%d", ans[0][0]);
    for(int i = 1; i < lev; i++)
        for(int j = 0; j < ans[i].size(); j++)
            printf(" %d", ans[i][j]);
}
