#include <cstdio>
#include <vector>
using namespace std;
int n, arr[100001], sum[100001], price, minians;
int dich(int k){
    int l = k, r = n;
    while(l != r){
        int mid = (l + r) / 2;
        if(sum[mid] - sum[k] < price)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main(){
    scanf("%d%d", &n, &price);
    sum[0] = 0;
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    minians = sum[n] + 1;
    for(int i = 0; i <= n; i++){
        int temp = dich(i), tempsum = sum[temp] - sum[i];
        if(tempsum > minians || tempsum < price) continue;
        if(tempsum < minians){
            ans.clear();
            minians = tempsum;
        }
        ans.push_back(make_pair(i, temp));
    }
    for(int i = 0; i < ans.size(); i++)
        printf("%d-%d\n", ans[i].first + 1, ans[i].second);
}
/* 
//最开始没有用二分法。也能过。考前复习的时候发现二分法也能做。有个case快了不少。
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, amount, arr[100001], mini = 999999999, a = 0, b = 0, tmpsum = 0;
    struct node{
        int a, b;
    };
    vector<node> ans, m;
    cin >> n >> amount;
    while(a < n){
        if(b < n && tmpsum < amount){
            scanf("%d", &arr[b]);
            tmpsum += arr[b++];
        }
        else{
            tmpsum -= arr[a++];
        }
        if(tmpsum == amount){
            ans.push_back(node{a + 1, b});
            mini = -1;
        }
        else if (tmpsum == mini){
            m.push_back(node{a + 1, b});
        }
        else if (tmpsum < mini && tmpsum > amount){
            mini = tmpsum;
            m.clear();
            m.push_back(node{a + 1, b});
        }
    }
    if(mini == -1)
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i].a << "-" << ans[i].b << endl;
    else
        for(int i = 0; i < m.size(); i++)
            cout << m[i].a << "-" << m[i].b << endl;
}
*/