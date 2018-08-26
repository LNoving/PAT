/***
 * 还是要多练才能快速AC。这么简单一道题又是花了半个小时
 * */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int tree[1001], n;
vector<int> ans;
bool isbst(int a, int b){
    if(a > b)return true;
    if(a == b){
        ans.push_back(tree[a]);
        return true;
    }
    int i = a + 1;
    while(tree[i] < tree[a] && i<=b)i++;
    for(int j = i; j <= b; j++)
        if(tree[j] < tree[a])return false;
    if(!isbst(a + 1, i - 1))return false;
    if(!isbst(i, b))return false;
    ans.push_back(tree[a]);
    return true;
}
bool ismirr(int a, int b){
    if(a > b)return true;
    if(a == b){
        ans.push_back(tree[a]);
        return true;
    }
    int i = a + 1;
    while(tree[i] >= tree[a] && i<=b)i++;
    for(int j = i; j <= b; j++)
        if(tree[j] >= tree[a])return false;
    if(!ismirr(a + 1, i - 1))return false;
    if(!ismirr(i, b))return false;
    ans.push_back(tree[a]);
    return true;
}
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> tree[i];
    }
    if(!isbst(0, n - 1)){
        ans.clear();
        if(!ismirr(0, n - 1)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i<ans.size(); i++){
        if(i)cout << " ";
        cout << ans[i];
    }
}
