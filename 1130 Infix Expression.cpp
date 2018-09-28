#include <iostream>
using namespace std;
struct {
    int l, r;
    string val;
}node, tree[21];
string pre(int p){
    if(tree[p].l == -1 && tree[p].r == -1)
        return tree[p].val;
    if(tree[p].l == -1)
        return "(" + tree[p].val + pre(tree[p].r) + ")";
    return "(" + pre(tree[p].l) + tree[p].val + pre(tree[p].r) + ")";
}
int main(){
    int n, findroot[21] = {0}, root = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tree[i].val >> tree[i].l >> tree[i].r;
        if(tree[i].l != -1)findroot[tree[i].l] = 1;
        if(tree[i].r != -1)findroot[tree[i].r] = 1;
    }
    while(findroot[root] == 1)root++;
    string s = pre(root);
    if(s.length() == 1)
        cout << s;
    for(int i = 1; i < s.length() - 1; i++)
        printf("%c", s[i]);
}
