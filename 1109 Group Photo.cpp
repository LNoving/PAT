#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node{
    string name;
    int h;
} arr[10001];
bool cmp(node a, node b){
    return a.h != b.h ? a.h < b.h : a.name > b.name;
}
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i].name >> arr[i].h;
    }
    sort(arr, arr + n, cmp);
    for(int i = k - 1; i >= 0; i--){
        vector<int> ans, l, r;
        for(int j = (i == k - 1 ? n - 1 : (i + 1) * (n / k) - 1); j >= i * (n / k); j--){
            if(((i == k - 1 ? n - 1 : (i + 1) * (n / k) - 1) - j) % 2 == 0)
                r.push_back(j);
            else
                l.push_back(j);
        }
        for(int j = l.size() - 1; j >= 0; j--)
            ans.push_back(l[j]);
        for(int j = 0; j < r.size(); j++)
            ans.push_back(r[j]);
        cout << arr[ans[0]].name;
        for(int j = 1; j < ans.size(); j++){
            cout << " " << arr[ans[j]].name;
        }
        printf("\n");
    }
}
