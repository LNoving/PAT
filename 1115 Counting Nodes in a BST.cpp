/**
 * The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 * ¡°less than or equal to¡±ÉóÌâºÜ¹Ø¼ü
 * */
#include <iostream>
#include <vector>
using namespace std;
struct {
    int val, l = -1, r = -1, lev = 0;
} bst[1001];
int ans[1001], n, depth = 0;
void ins(int root, int k, int lev){
    lev++;
    if(bst[root].val >= bst[k].val){
        if(bst[root].l == -1){
            bst[root].l = k;
            bst[k].lev = lev;
            if(lev > depth)
                depth = lev;
        }
        else{
            ins(bst[root].l, k, lev);
        }
    }
    else{
        if(bst[root].r == -1){
            bst[root].r = k;
            bst[k].lev = lev;
            if(lev > depth)
                depth = lev;
        }
        else{
            ins(bst[root].r, k, lev);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> bst[i].val;
        if(i)
            ins(0, i, 0);
    }
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(bst[i].lev == depth)
            a++;
        if(bst[i].lev == depth - 1)
            b++;
    }
    printf("%d + %d = %d", a, b, a + b);
}
