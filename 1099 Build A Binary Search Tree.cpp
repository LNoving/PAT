/**
 * 希望明天遇到的题都和这道一样简单。加油，好运！
 * 2018.12.4 : 看来当时并没有很好运。不过12月8号这次考试一定会好运的！
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> v;
vector<int> ans, vals, arr;
int n, cnt = 0;
void ins(int k){
    if(v[k].first != -1)
        ins(v[k].first);
    ans[k] = arr[cnt++];
    if(v[k].second != -1)
        ins(v[k].second);
}
int main(){
    cin >> n;
    v.resize(n);
    arr.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ins(0);
    vector<int> lev;
    lev.push_back(0);
    while(!lev.empty()){
        vector<int> temp;
        for(int i = 0; i < lev.size(); i++){
            if(cnt-- != n)printf(" ");
            printf("%d", ans[lev[i]]);
            if(v[lev[i]].first != -1)
                temp.push_back(v[lev[i]].first);
            if(v[lev[i]].second != -1)
                temp.push_back(v[lev[i]].second);
        }
        lev = temp;
    }
}
/*
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
*/