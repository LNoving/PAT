#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, tree[101][3], arr[101], p = 0, flag = 0;
void in(int root){
    if(tree[root][0] != -1)
        in(tree[root][0]);
    tree[root][2] = arr[p++];
    if(tree[root][1] != -1)
        in(tree[root][1]);
}
int main(){
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> tree[i][0] >> tree[i][1];
    }
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    in(0);
    vector<int> cur, tmp;
    cur.push_back(0);
    while(!cur.empty()){
        for(int i = 0; i<cur.size(); i++){
            if(tree[cur[i]][0] != -1)
                tmp.push_back(tree[cur[i]][0]);
            if(tree[cur[i]][1] != -1)
                tmp.push_back(tree[cur[i]][1]);
            if(flag)cout << " ";flag++;
            cout << tree[cur[i]][2];
        }
        cur.swap(tmp);
        tmp.clear();
    }
}
