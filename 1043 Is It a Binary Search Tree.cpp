/**
 * 第二遍做的时候想让代码短一点，但是太粗心了，出现了很多低级bug。一定要细心啊！
 * */
#include <cstdio>
#include <vector>
using namespace std;
int n, arr[1001];
vector<int> ans;
bool pre(int l, int r, int flag){
    if(l > r) return 1;
    int i = l + 1, f;
    while(i <= r && (flag == 1 ? arr[i] < arr[l] : arr[i] >= arr[l]))
        i++;
    for(int j = i + 1; j <= r; j++)
        if(flag == 1 ? arr[j] < arr[l] : arr[j] >= arr[l]){
            ans.clear();
            return 0;
        }
    if(pre(l + 1, i - 1, flag) && pre(i, r, flag)){
        ans.push_back(arr[l]);
        return 1;
    }
    ans.clear();
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if(pre(0, n - 1, 1) || pre(0, n - 1, 0)){
        printf("YES\n");
        printf("%d", ans[0]);
        for(int i = 1; i < ans.size(); i++)
            printf(" %d", ans[i]);
    }
    else
        printf("NO\n");
}

/***
 * 还是要多练才能快速AC。这么简单一道题又是花了半个小时
 * */
/*
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
*/