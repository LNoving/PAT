/**
 * For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
 * 对于每个节点，左右子树权重相同，这是个递归的定义。做题的时候忘记了这点，只是判断了每个节
 * 点到根节点的权重，后两个case老是过不去。于是写代码30分钟，debug俩小时。。后来才想清楚。
 * 网上能搜到的解法基本都是用链表建树，直接dfs的很少，还是有一点优越感的23333
 * */
#include <iostream>
#include <vector>
using namespace std;
int k, rbt[100] = {0};
int dfs(int l, int r){
    if(l > r)return 0;
    if(l == r){
        return rbt[l] > 0 ? 1 : 0;
    }
    int i = l + 1;
    while(i <= r && abs(rbt[i]) < abs(rbt[l]))i++;
    if(rbt[l] > 0){
        int lw = dfs(l + 1, i - 1), rw = dfs(i, r);
        return lw == rw && lw != -1 ? lw + 1 : -1;
    }
    else{
        if(rbt[l + 1] < 0 || (i <= r && rbt[i] < 0) )return -1;
        int lw = dfs(l + 1, i - 1), rw = dfs(i, r);
        return lw == rw && lw != -1 ? lw : -1;
    }
}
int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> rbt[j];
        }
        if(rbt[0] > 0 && dfs(0, n - 1) != -1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        fill(rbt, rbt + 100, 0);
    }
}
