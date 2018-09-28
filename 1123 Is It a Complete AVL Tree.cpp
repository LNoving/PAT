/**
 * 虽说前面三道题都很简单，但是这第四道题也太难了吧。我前前后后写了有三个多小时。
 * */
#include <iostream>
#include <vector>
using namespace std;
struct {
    int val, l, r, w;
} node, t[30];
int n, r = 0; // r means root
int update(int k){
    if(t[k].val == 0)return 0;
    if(t[k].l == t[k].r && t[k].l == 0){
        t[k].w = 1;
        return 1;
    }
    int l = update(t[k].l), r = update(t[k].r);
    t[k].w = 1 + (l > r ? l : r);
    return t[k].w;
}
void change_root(int old, int ne){
    if(r == old)r = ne;
    for(int i = 1; i < 30; i++){
        if(t[i].l == old)
            t[i].l = ne;
        if(t[i].r == old)
            t[i].r = ne;
    }
}
void ll(int k){
    int l = t[k].l;
    change_root(k, l);
    t[k].l = t[l].r;
    t[l].r = k;
}
void rr(int k){
    int r = t[k].r;
    change_root(k, r);
    t[k].r = t[r].l;
    t[r].l = k;
}
void lr(int k){
    int lr = t[t[k].l].r;
    change_root(k, lr);
    t[t[k].l].r = t[lr].l;
    t[lr].l = t[k].l;
    t[k].l = t[lr].r;
    t[lr].r = k;
}
void rl(int k){
    int rl = t[t[k].r].l;
    change_root(k, rl);
    t[t[k].r].l = t[rl].r;
    t[rl].r = t[k].r;
    t[k].r = t[rl].l;
    t[rl].l = k;
}
void ins(int k, int root){
    if(root == k)return;
    if(t[k].val < t[root].val){
        if(t[root].l == 0)
            t[root].l = k;
        else
            ins(k, t[root].l);
    }
    else{
        if(t[root].r == 0)
            t[root].r = k;
        else
            ins(k, t[root].r);
    }
    update(r);
    int l = t[root].l, r = t[root].r;
    if(t[l].w - t[r].w >= 2)
        if(t[t[l].l].w > t[t[l].r].w)
            ll(root);
        else
            lr(root);
    if(t[l].w - t[r].w <= -2)
        if(t[t[r].l].w < t[t[r].r].w)
            rr(root);
        else
            rl(root);
    update(r);
}
int main(){
    int cnt = 0, a[30], flag = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i].val;
        if(r == 0)r = i;
        ins(i, r);
    }
    vector<int> v;
    v.push_back(r);
    while(!v.empty()){
        vector<int> tmp;
        for(int i = 0; i < v.size(); i++){
            a[cnt++] = t[v[i]].val;
            if(t[v[i]].l == 0){
                if(flag == 0)
                    flag = 1;
            }
            else{
                if(flag == 1)
                    flag = 2;
                tmp.push_back(t[v[i]].l);
            }
            if(t[v[i]].r == 0){
                if(flag == 0)
                    flag = 1;
            }
            else{
                if(flag == 1)
                    flag = 2;
                tmp.push_back(t[v[i]].r);
            }
        }
        v = tmp;
    }
    printf("%d", a[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", a[i]);
    if(flag == 2)
        printf("\nNO");
    else
        printf("\nYES");
}
